#ifndef SPECKER_GAME_PLAYER_ARCHETYPES_H
#define SPECKER_GAME_PLAYER_ARCHETYPES_H

#include "Player.h"
#include <string>

class GreedyPlayer : public Player {
public:
    GreedyPlayer(const std::string &n);

    const std::string &getType() const override;

    Move play(const State &s) override;

private:
    std::string type;
};
#endif //SPECKER_GAME_PLAYER_ARCHETYPES_H