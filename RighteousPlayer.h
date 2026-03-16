#ifndef SPECKER_GAME_RIGHTEOUSPLAYER_H
#define SPECKER_GAME_RIGHTEOUSPLAYER_H

#include "Player.h"
#include <string>

class RighteousPlayer: public Player {
public:
    RighteousPlayer(const std::string &s);

    const std::string &getType() const override;

    Move play(const State &s) override;
private:
    std::string type;
};
#endif //SPECKER_GAME_RIGHTEOUSPLAYER_H