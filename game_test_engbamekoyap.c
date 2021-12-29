#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_aux.h"

/***********************usage***************************************************************************/
void usage(char* exeFile) {
  fprintf(stderr, "Usage: %s <testname>\n", exeFile);
  exit(EXIT_FAILURE);
}

/***********************test_game_get_current_nb_tents_row**********************************************/
bool test_game_get_current_nb_tents_row() {
  game g = game_default();
  game G = game_default_solution();
  assert(g);
  assert(G);

  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 0, 1, TENT);
  game_set_square(g, 0, 2, TENT);
  game_set_square(g, 0, 7, TENT);

  cgame tmp = g;
  assert(tmp);

  if (game_get_current_nb_tents_row(g, 0) != 4 ||
      game_get_current_nb_tents_row(G, 4) != 4) {
    fprintf(stderr, "Warning: The current number of tents is invalid.\n");
    game_delete(g);
    game_delete(G);
    return false;
  }
  game_delete(g);
  game_delete(G);
  return true;
}

/***********************test_game_play_move*************************************************************/
bool test_game_play_move() {
  game g = game_default();
  assert(g);

  game_play_move(g, 1, 1, EMPTY);
  if (game_get_square(g, 1, 1) == TREE || game_get_square(g, 1, 1) == GRASS ||
      game_get_square(g, 1, 1) != EMPTY || game_get_square(g, 1, 1) == TENT) {
    game_delete(g);
    return false;
  }
  game_play_move(g, 6, 0, TENT);
  if (game_get_square(g, 6, 0) == TREE || game_get_square(g, 6, 0) == GRASS ||
      game_get_square(g, 6, 0) != TENT || game_get_square(g, 6, 0) == EMPTY) {
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}

/***********************MAIN*****************************************************************/
bool dummy(char* dummy) { return (strcmp(dummy, "dummy") == 0); }
int main(int argc, char* argv[]) {
  if (argc != 2) usage(argv[0]);
  bool jeux = false;
  /*------------APPEL--DES--FONCTIONS-------------------------------------------------------*/
  if (strcmp(argv[1], "dummy") == 0)
    jeux = dummy(argv[1]);
  else if (strcmp(argv[1], "game_play_move") == 0)
    jeux = test_game_play_move();
  else if (strcmp(argv[1], "game_get_current_nb_tents_row") == 0)
    jeux = test_game_get_current_nb_tents_row();

  /*-------Finale--------------------------------------------------*/
  if (!jeux) {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n\n", argv[1]);
    return EXIT_FAILURE;
  }
  fprintf(stderr, "Test \"%s\" finished: SUCCESS\n\n", argv[1]);
  return EXIT_SUCCESS;
}
/***********************NGBAME-KOYAPOLO-EMMANUEL*********************************************************/
/**************************All right
 * reserved************************************************************/