#ifndef SPECKER_GAME_MOVE_STATE_H
#define SPECKER_GAME_MOVE_STATE_H
#include <iostream>
class Move{
public:
    //Take sc coins from heap sc and put tc coins to heap th.
    Move(int sh, int sc, int th, int tc);

    int getSource() const;
    int getSourceCoins() const;
    int getTarget() const;
    int getTargetCoins() const;

    friend std::ostream &operator << (std::ostream &out, const Move &move);
private:
    int source_heap, source_coins, target_heap, target_coins;
};

class State{
public:
    //State with h heaps, where the i-th heap starts with c[i] coins.
    // A total of n players are in the game, numbered from 0 to n-1,
    // and player 0 is the first to play.
    State(int h, const int c[], int n);

    ~State();

    void next(const Move &move);    // may throw logic_error

    bool winning() const;

    int getHeaps() const;
    int getCoins(int h) const;
    int getPlayers() const;
    int getPlaying() const;

    friend std::ostream &operator << (std::ostream &out, const State &state);
private:
    int heaps, players;
    int playing=0;
    int *heap_coins;
};
#endif //SPECKER_GAME_MOVE_STATE_H