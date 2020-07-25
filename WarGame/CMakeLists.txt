cmake_minimum_required(VERSION 3.16)
project(WarGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(WarGame DemoGame.cpp DemoGame.hpp Demo.cpp Board.cpp Board.hpp FootCommander.cpp FootCommander.hpp FootSoldier.cpp FootSoldier.hpp Paramedic.cpp Paramedic.hpp ParamedicCommander.cpp ParamedicCommander.hpp Sniper.cpp Sniper.hpp SniperCommander.cpp SniperCommander.hpp Soldier.hpp)