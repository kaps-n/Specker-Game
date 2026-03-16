#ifndef CONTEST
#include "Player.h"
#endif
using namespace std;

Player::Player(const string &n): name(n) {
}

ostream &operator << (ostream &out, const Player &player)
{
    out << player.getType() << " player " << player.name;
    return out;
}