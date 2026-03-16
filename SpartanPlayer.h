#ifndef SPECKER_GAME_SPARTANPLAYER_H
#define SPECKER_GAME_SPARTANPLAYER_H

#include "Player.h"
#include <string>

class SpartanPlayer : public Player {
public:
    SpartanPlayer(const std::string &n);

    const std::string &getType() const override;

    Move play(const State &s) override;
private:
    std::string type;
};

#endif //SPECKER_GAME_SPARTANPLAYER_H