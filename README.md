# Specker Game Program

Welcome to the README for the Specker Game Program.

This program was created for the execution and simulation of a mathematical strategy game called the Specker Game (a variation of Nim).

## Table of contents:

* [1. What is the Specker Game?](#1-what-is-the-specker-game)
* [2. What does this program accomplish?](#2-what-does-this-program-accomplish)
  * [How do the player archetypes work?](#how-do-the-ai-personalities-work)
  * [⬇️ How to compile and execute this program](#️-how-to-compile-and-execute-this-program)
* [3. ⚠️ Test runs and expected results](#3-️-test-runs-and-expected-results)
* [4. 💡 What inspired me to make this?](#4--what-inspired-me-to-make-this)

---

## 1. What is the Specker Game?

The Specker Game (similar to Nim) is a mathematical game of strategy in which multiple players take turns removing coins from distinct heaps. On each turn, a player must choose a heap and remove a valid number of coins from it. He then has the option to put place back some coins in another heap. The game ends when all heaps are completely empty, where the winning player is the one that played last.

For example: If the game starts with 3 heaps containing 10, 20, and 17 coins respectively, a player might take 5 coins from the second heap, leaving the state as 10, 15, and 17.

## 2. What does this program accomplish?

Rather than a human-playable game, this program serves as an Object-Oriented C++ simulation. It pits four uniquely designed AI bots against each other to demonstrate Object-Oriented Programming principles like inheritance, polymorphism, and dynamic memory management.

### How do the AI player archetypes work?

Using polymorphism derived from a core `Player` class, the program features four distinct algorithms:
* **The Greedy Player:** Highly aggressive. Always aims for the heap with the most coins and takes all of them, without returning any back.
* **The Spartan Player:** Plays the long game. Targets the largest heap but only removes exactly 1 coin, without returning any back.
* **The Sneaky Player:** Flies under the radar. Always empties the smallest available heap on the board, and again doesnt return any back.
* **The Righteous Player:** The equalizer. Takes half the coins from the largest heap and gives back 1 less to the smallest heap.

### ⬇️ How to compile and execute this program

**Using CMake (CLion):**
Open the project folder in CLion, allow CMake to load the `CMakeLists.txt` file, and click the Run button.

**Using Command Line (g++):**
Navigate to the directory containing the source files and compile them together:
```bash
g++ *.cpp -o specker_game
./specker_game
```

## 4. 💡 What inspired me to make this?
Honestly, the main reason I built this was simply because I wanted to get better at coding. I was learning a lot about Object-Oriented Programming (OOP) in my classes, but I wanted to actually practice it on a real project instead of just doing standard homework assignments.

Concepts like abstract classes, polymorphism, and virtual functions can feel pretty theoretical when you just read about them. I thought it would be fun to take those concepts and use them to build a working game engine. 

Since games like Specker and Nim are so heavily based on math and logic, it felt like a great way to combine my university coursework with writing clean, modular C++. Plus, writing the logic for different AI bots and then watching them fight each other to win the game was just a really cool way to see my code actually work!
