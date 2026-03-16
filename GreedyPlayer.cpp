#ifndef CONTEST
#include "GreedyPlayer.h"
#endif
using namespace std;

GreedyPlayer::GreedyPlayer(const std::string &n):
    Player(n), type("Greedy"){
}

const std::string &GreedyPlayer::getType() const {
    return type;
}

Move GreedyPlayer::play(const State &s){

    int biggest_heap = 0;
    int coins = 0;

    for (int i = 0; i < s.getHeaps(); ++i) {
        if (s.getCoins(i) > s.getCoins(biggest_heap)) {
            biggest_heap = i;
        }
    }
    coins = s.getCoins(biggest_heap);

    return Move(biggest_heap, coins, 0, 0);
}
