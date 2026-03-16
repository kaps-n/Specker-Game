#include <cmath>
#ifndef CONTEST
#include "RighteousPlayer.h"
#endif
using namespace std;

RighteousPlayer::RighteousPlayer(const string &n):
    Player(n), type("Righteous"){
}

const string &RighteousPlayer::getType() const {
    return type;
}

Move RighteousPlayer::play(const State &s) {

    int biggest_heap = 0;
    int smallest_heap = 0;
    int coins = 0;

    for (int i = 0; i < s.getHeaps(); ++i) {
        if (s.getCoins(i) > s.getCoins(biggest_heap)) {
            biggest_heap = i;
        }
    }
    for (int i = 0; i < s.getHeaps(); ++i) {
        if (s.getCoins(i) < s.getCoins(smallest_heap)) {
            smallest_heap = i;
        }
    }
    coins = ceil(s.getCoins(biggest_heap) / 2.0);

    return Move(biggest_heap, coins, smallest_heap, coins-1);
}