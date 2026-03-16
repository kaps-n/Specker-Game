#include "Game.h"
#include "Player.h"
#include "GreedyPlayer.h"
#include "SpartanPlayer.h"
#include "SneakyPlayer.h"
#include "RighteousPlayer.h"

using namespace std;

int main() {
    // Set up a game with 3 heaps and 4 players
    Game specker(3, 4);

    // Add the starting coins
    specker.addHeap(10);
    specker.addHeap(20);
    specker.addHeap(17);

    // Add one of each npc personality
    specker.addPlayer(new SneakyPlayer("Tom"));
    specker.addPlayer(new SpartanPlayer("Mary"));
    specker.addPlayer(new GreedyPlayer("Alan"));
    specker.addPlayer(new RighteousPlayer("Robin"));

    // Run the game and print to the console
    specker.play(cout);

    return 0;
}