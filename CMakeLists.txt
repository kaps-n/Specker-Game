cmake_minimum_required(VERSION 4.1)
project(Specker_Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Specker_Game main.cpp
        Move_State.h
        Move_State.cpp
        Player.h
        Player.cpp
        GreedyPlayer.h
        GreedyPlayer.cpp
        SpartanPlayer.h
        SpartanPlayer.cpp
        SneakyPlayer.h
        SneakyPlayer.cpp
        RighteousPlayer.h
        RighteousPlayer.cpp
        Game.h
        Game.cpp
)
