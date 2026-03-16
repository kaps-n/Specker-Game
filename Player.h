#ifndef SPECKER_GAME_PLAYER_H
#define SPECKER_GAME_PLAYER_H
#include <string>
#include "Move_State.h"

class Player{
public:
    Player(const std::string &n);

    virtual ~Player() = default;

    virtual const std::string &getType() const = 0;

    virtual Move play(const State &s) = 0;

    friend std::ostream &operator << (std::ostream &out, const Player &player);
private:
    std::string name;
};

#endif //SPECKER_GAME_PLAYER_H