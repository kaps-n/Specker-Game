#ifndef CONTEST
#include "Game.h"
#include "Player.h"
#endif
using namespace std;

Game::Game(int h, int p):
    heaps(h), players(p), heaps_added(0), players_added(0) {
    heap_coins = new int[heaps];
    player_list = new Player*[players];
}

Game::~Game() {
    delete[] heap_coins;
    for (int i = 0; i < players_added; i++) {
        delete player_list[i];
    }

    delete[] player_list;
}

void Game::addHeap(int coins) {
    if (coins < 0 || heaps_added >= heaps) {
        throw logic_error("Max number of heaps already reached");
    }
    heap_coins[heaps_added++] = coins;
}

void Game::addPlayer(Player *player) {
    if (players_added >= players) {
        throw logic_error("Max number of players already reached");
    }
    player_list[players_added++] = player;
}

int Game::getPlayers() const {
    return players_added;
}

const Player* Game::getPlayer(int p) const {
    if (p < 0 || p >= players_added) {
        throw logic_error("Invalid player");
    }
    return player_list[p];
}

void Game::play(std::ostream &out) {
    if (players_added == 0){
        throw logic_error("Cannot start a game with 0 players");
    }

    if (heaps_added == 0) {
        throw logic_error("Cannot start a game with 0 heaps");
    }

    State state(heaps_added, heap_coins, players_added);

    while(true)
    {
        int total_coins = 0;
        for(int i = 0; i < state.getHeaps(); ++i){
            total_coins += state.getCoins(i);
        }

        if (total_coins == 0){
            break;
        }

        out << "State: " << state << endl;

        int current_turn = state.getPlaying();
        Player *live_player = player_list[current_turn];

        Move m = live_player->play(state);
        out << *live_player << ' ' << m << endl;
        state.next(m);
    }

    out << "State: " << state << endl;

    int winner = (state.getPlaying() + players -  1) % players;

    out << *player_list[winner] << " wins" << endl;
}