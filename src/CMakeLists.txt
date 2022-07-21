cmake_minimum_required(VERSION 3.22)
project(Ultimate_TicTac_Toe C)

set(CMAKE_C_STANDARD 99)

add_executable(Ultimate_TicTac_Toe main.c boards.c boards.h game.c game.h plays.c plays.h ui.c ui.h utils.c utils.c)
