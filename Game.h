#ifndef SPECKER_GAME_GAME_H
#define SPECKER_GAME_GAME_H
#include "Player.h"
#include "Move_State.h"

class Game {
public:
    Game(int h, int p);
    ~Game();

    void addHeap(int coins);    // may throw logic_error
    void addPlayer(Player *player); // may throw logic_error
    void play(std::ostream &os);    // may throw logic_error

    int getPlayers() const;
    const Player *getPlayer(int p) const;   // may throw logic_error

private:
    int heaps, players, *heap_coins;
    int heaps_added, players_added;
    Player **player_list;
};
#endif //SPECKER_GAME_GAME_H