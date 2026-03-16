#ifndef CONTEST
#include "SpartanPlayer.h"
#endif
using namespace std;

SpartanPlayer::SpartanPlayer(const string &n):
    Player(n), type("Spartan"){
}

const string &SpartanPlayer::getType() const {
    return type;
}

Move SpartanPlayer::play(const State &s) {

    int biggest_heap = 0;

    for (int i = 0; i < s.getHeaps(); ++i) {
        if (s.getCoins(i) > s.getCoins(biggest_heap)) {
            biggest_heap = i;
        }
    }
    return Move(biggest_heap, 1, 0, 0);
}
