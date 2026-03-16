#ifndef CONTEST
#include "SneakyPlayer.h"
#endif
using namespace std;

SneakyPlayer::SneakyPlayer(const std::string &n):
    Player(n), type("Sneaky") {
}

const string &SneakyPlayer::getType() const {
    return type;
}

Move SneakyPlayer::play(const State &s) {

    int smallest_heap = 0;
    int coins = 0;

    for (int i = 0; i < s.getHeaps(); ++i) {
        if (s.getCoins(i) > 0) {
            if (s.getCoins(i) < s.getCoins(smallest_heap)) {
                smallest_heap = i;
            }
        }
    }
    coins = s.getCoins(smallest_heap);

    return Move(smallest_heap, coins, 0, 0);
}