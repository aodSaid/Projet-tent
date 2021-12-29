# TENTS A22B

## General information
This project is a group work by NGBAME KOYAPOLO Emmanuel, AZEMA Farah, ELHADJ SAIDOU Diallo et Bani Jarid, Jad.
It aims to recreate the game Tents (c.f. the game documentation [HERE](https://pt2.gitlabpages.inria.fr/tents/v1/))

In its current state, the project should contain the following files:

* CMakeLists.txt
* game_aux.c
* game_aux.h
* game_text.c
* game.h
* game.o

## Implementation

Here is the list of all functions of game.c with the name of the person assigned to create it next to its name:

**game.c functions**

* game_new: azema
* game_new_empty : azema
* game_copy : azema
* game_equal : azema
* game_delete : azema
* game_set_square : 
* game_get_square : 
* game_set_expected_nb_tents_row : jbanijarid
* game_set_expected_nb_tents_col : jbanijarid
* game_get_expected_nb_tents_row : jbanijarid
* game_get_expected_nb_tents_col : jbanijarid
* game_get_expected_nb_tents_all : jbanijarid
* game_get_current_nb_tents_row : 
* game_get_current_nb_tents_col : 
* game_get_current_nb_tents_all : 
* game_play_move : jbanijarid //
* game_check_move : engbamekoyap
* game_is_over : engbamekoyap
* game_fill_grass_row : engbamekoyap
* game_fill_grass_col : engbamekoyap
* game_restart : engbamekoyap
## Known bugs

## Version and changelog

CURRENT VERSION : 1.6.0


Changelog: 1.6.0 - TD6
-Replaced game.o with game.c
-Defined the 'game' struct
-Created the empty shell for game.c functions
-Updated CMakeLists.txt and .gitignore to reflect that change
-Added .clang-format file


TD - 5:

1.5.2
-Added most of the other tests (game_play_move missing)
-Fixed an oversight in game_text.c : player could crash the game by attempting to play a move out of bounds


1.5.1
-Added 6 tests in game_test_skadionik.c
-Replaced game.o with a fixed version
-Fixed a bug in game_text.c : game started with the default solution instead of the default game
-Fixed a bug in game_text.c : game didn't print "Losing move" if it was because of a misplaced grass
-Fixed a typo in game_text.c : game didn't line break after printing the "Quit" message

# Répartition du travail du TD6

### Partie de Elhadj
1. game_get_current_nb_tents_col(cgame g, uint j)
2.  game_get_current_nb_tents_row(cgame g, uint i)
3. game_get_current_nb_tents_all(cgame g)
4.  game_get_square(cgame g, uint i, uint j) 
5.   game_set_square(game g, uint i, uint j, square s)
### Partie de Farah
1. game_new(square *square, uint *nb_tents_row, uint *nb_tents_col) 
2.  game_new_empty(void)
3. game_copy(cgame g)
4.  game_equal(cgame g1, cgame g2)
5.   game_delete(game g)
### Partie de jad
1. game_play_move(game g, uint i, uint j, square s)
2.  game_set_expected_nb_tents_col(game g, uint j, uint nb_tents) 
3. game_set_expected_nb_tents_row(game g, uint i, uint nb_tents)
4.  game_get_expected_nb_tents_all(cgame g)
5.   game_get_expected_nb_tents_row(cgame g, uint i)
6.    game_get_expected_nb_tents_col(cgame g, uint j)
### Partie de Emmanuelle
1. game_check_move(cgame g, uint i, uint j, square s) { return 1; }
2.  game_is_over(cgame g) { return true; }
3. game_fill_grass_row(game g, uint i) {}
4.  game_fill_grass_col(game g, uint j) {}
5.   game_restart(game g) {}

# Répartition du travail du TD7