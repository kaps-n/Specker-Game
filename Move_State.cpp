#ifndef CONTEST
#include "Move_State.h"
#endif

using namespace std;

Move::Move(int sh, int sc, int th, int tc):
    source_heap(sh), source_coins(sc), target_heap(th), target_coins(tc) { }

int Move::getSource() const{
    return source_heap;
}
int Move::getSourceCoins() const {
    return source_coins;
}
int Move::getTarget() const {
    return target_heap;
}
int Move::getTargetCoins() const {
    return target_coins;
}

ostream& operator << (ostream &out, const Move &move){
    if(move.getTargetCoins() != 0)
        out << "takes " << move.source_coins << " coins from heap " << move.source_heap << " and puts " << move.target_coins << " coins to heap " << move.target_heap;
    else
        out << "takes " << move.source_coins << " coins from heap " << move.source_heap << " and puts nothing";
    return out;
}

State::State(int h, const int c[], int n): heaps(h), players(n)
{
    heap_coins = new int[heaps];
    for (int i = 0; i < h; ++i){
        heap_coins[i] = c[i];
    }
}

State::~State() {
    delete[] heap_coins;
}

void State::next(const Move &move)
    {
    if((move.getSource() < 0) || (move.getSource() >= heaps) || (move.getTarget() < 0) || (move.getTarget() >= heaps))
        throw logic_error("invalid heap");

    if((move.getSourceCoins() < 1) || (move.getTargetCoins() < 0) || (move.getTargetCoins() >= move.getSourceCoins()) || (move.getSourceCoins() > heap_coins[move.getSource()]))
        throw logic_error("invalid number of coins");

    heap_coins[move.getSource()] -= move.getSourceCoins();
    heap_coins[move.getTarget()] += move.getTargetCoins();
    playing = (playing + 1) % players;
    }

bool State::winning() const {
    int total_coins=0;
    for (int i=0; i<heaps; ++i){
        total_coins += heap_coins[i];
    }
    return total_coins == 0;
}

int State::getHeaps() const {
    return heaps;
}

int State::getCoins(int h) const{
        if (h < 0 || h >= heaps){
            throw logic_error("invalid heap");
        }
        return heap_coins[h];
}

int State::getPlayers() const {
    return players;
}

int State::getPlaying() const {
    return playing;
}

ostream &operator << (ostream &out, const State &state)
{
    if (state.heaps > 0){
        for (int i=0; i<state.heaps-1; ++i){
            out << state.heap_coins[i] << ", ";
        }
        out << state.heap_coins[state.heaps-1] << " with " << state.playing << '/' << state.players << " playing next";
    }
    return out;
}