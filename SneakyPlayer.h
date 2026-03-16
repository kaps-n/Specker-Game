#ifndef SPECKER_GAME_SNEAKYPLAYER_H
#define SPECKER_GAME_SNEAKYPLAYER_H

#include "Player.h"
#include <string>

class SneakyPlayer: public Player {
public:
    SneakyPlayer(const std::string &n);

    const std::string &getType() const override;

    Move play(const State &s) override;
private:
    std::string type;
};
#endif //SPECKER_GAME_SNEAKYPLAYER_H