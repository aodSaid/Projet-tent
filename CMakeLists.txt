cmake_minimum_required(VERSION 2.6)

project("game_text" C)

enable_testing()
include(CTest)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c99 -g --coverage")
set(CMAKE_AR "ar")

add_library(game game_ext.c game.c game_private.c game_aux.c queue.c game_tools.c)

add_executable(game_tools_test game_tools_test.c)
add_executable(game_text game_text.c)
add_executable(game_solve game_solve.c)

target_link_libraries(game_text game)
target_link_libraries(game_tools_test game)
target_link_libraries(game_solve game)

add_test(test_game_save ./game_tools_test game_save_test)
add_test(test_game_load ./game_tools_test game_load_test)
add_test(test_game_solve ./game_tools_test game_solve_test)
add_test(test_game_nb_sol ./game_tools_test game_nb_solutions_test)

