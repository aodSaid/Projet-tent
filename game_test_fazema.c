#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_aux.h"
#include "game_ext.h"
#include "game_tools.h"

void usage(char *nom) { fprintf(stderr, "%s <chaine1>  ...\n", nom); }

/******************game_delete********************/

bool test_game_delete() {
  game g = game_default();
  if (g == NULL) {
    fprintf(stderr, "Error! problem allocation");
    return false;
  }
  game_delete(g);
  return true;
}

/******************game_print********************/
bool test_game_print() {
  game g = game_default();

  if (g == NULL) {
    fprintf(stderr, "Error! game print");
    return false;
  }
  game_print(g);
  game_delete(g);
  return true;
}
/******************game_copy********************/

bool test_game_copy() {
  game g = game_default();
  game g2 = game_copy(g);
  if (g == NULL || g2 == NULL) {
    fprintf(stderr, "Error! problem allocation");
    game_delete(g);
    game_delete(g2);
    return false;
  }
  if (game_equal(g, g2)) {
    game_delete(g);
    game_delete(g2);
    return true;
  } else {
    game_delete(g);
    game_delete(g2);
    return false;
  }
}
/******************game_equal********************/
bool test_game_equal() {
  game g = game_default();
  game g2 = game_default();
  game g3 = game_default_solution();
  if (g == NULL || g2 == NULL || g3 == NULL) {
    fprintf(stderr, "Error! problem allocation");
    game_delete(g);
    return false;
  }

  if (!game_equal(g, g2)) {
    fprintf(stderr, "ERROR! game equal");
    game_delete(g);
    game_delete(g2);
    return false;
  }
  if (game_equal(g, g3)) {
    fprintf(stderr, "ERROR! game equal");
    game_delete(g);
    game_delete(g3);
    return false;
  } else {
    game_delete(g);
    game_delete(g2);
    game_delete(g3);
    return true;
  }
}
bool test_game_restart() {
  game g = game_default();
  game gs = game_default_solution();
  assert(g);

  game_restart(gs);
  if (!game_equal(g, gs)) {
    return false;
  }
  game_delete(g);
  game_delete(gs);
  return true;
}
/******************game_get_current_nb_tents_all******************/
bool test_game_get_current_nb_tents_all() {
  game g = game_default();
  game G = game_default_solution();
  assert(g);
  assert(G);

  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 0, 1, TENT);
  game_set_square(g, 0, 2, TENT);
  game_set_square(g, 0, 3, TENT);

  if (game_get_current_nb_tents_all(g) != 4 ||
      game_get_current_nb_tents_all(G) != 12) {
    fprintf(stderr, "Warning: The number of tents is invalid.\n");
    return false;
  }
  game_delete(g);
  game_delete(G);
  return true;
}
/******************game_get_expected_nb_tents_all******************/
bool test_game_get_expected_nb_tents_all(void) {
  game g = game_default();
  if (g == NULL) return false;
  uint t = 0;
  uint t1 = 0;
  for (uint i = 0; i < game_nb_rows(g); i++) {
    t += game_get_expected_nb_tents_row(g, i);
  }
  for (uint i = 0; i < game_nb_cols(g); i++) {
    t1 += game_get_expected_nb_tents_col(g, i);
  }
  if (game_get_expected_nb_tents_all(g) != t ||
      game_get_expected_nb_tents_all(g) != t1) {
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}

/*-------------------*/

bool test_game_is_over() {
  game g = game_default();
  game G = game_default_solution();
  if (g == NULL || G == NULL) {
    fprintf(stderr, "Error\n");
    return false;
  }

  if (game_is_over(g) || !game_is_over(G)) {
    fprintf(stderr, "Error\n");
    return false;
  }
  game_delete(g);
  game_delete(G);
  return true;
}
/////////////tests v2///////////////

uint squares[8 * 8] = {
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};
uint nb_tents_row[8] = {0};
uint nb_tents_col[8] = {0};
bool test_game_nb_rows() {
  game g = game_new_ext(8, 8, squares, nb_tents_row, nb_tents_col, true, true);
  if (g == NULL) {
    fprintf(stderr, "Error! problem allocation");
    return false;
  }
  game_delete(g);
  return true;
}

bool test_game_nb_cols() {
  game g = game_new_ext(8, 8, squares, nb_tents_row, nb_tents_col, true, true);
  if (g == NULL) {
    fprintf(stderr, "Error! problem allocation");
    return false;
  }
  game_delete(g);
  return true;
}
////////////////TD10/////////////
bool test_game_load() {
  game game_load1 = game_load("game_3x3.tnt");
  if (game_load1 == NULL) {
    fprintf(stderr, "Error!!\n");
    exit(EXIT_FAILURE);
  }
  if ((game_nb_rows(game_load1) != 3) || (game_nb_cols(game_load1) != 3) ||
      (game_is_diagadj(game_load1) != 0) ||
      (game_is_wrapping(game_load1) != 0)) {
    game_delete(game_load1);
    return false;
  }

  if ((game_get_expected_nb_tents_row(game_load1, 0) != 1) ||
      (game_get_expected_nb_tents_row(game_load1, 1) != 0) ||
      (game_get_expected_nb_tents_row(game_load1, 2) != 1)) {
    game_delete(game_load1);
    return false;
  }
  if ((game_get_expected_nb_tents_col(game_load1, 0) != 1) ||
      (game_get_expected_nb_tents_col(game_load1, 1) != 0) ||
      (game_get_expected_nb_tents_col(game_load1, 2) != 1)) {
    game_delete(game_load1);
    return false;
  }
  if (game_get_square(game_load1, 0, 0) != EMPTY ||
      game_get_square(game_load1, 1, 0) != TREE ||
      game_get_square(game_load1, 1, 2) != TREE) {
    return false;
  }
  game_delete(game_load1);
  return true;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    usage(argv[0]);
    return EXIT_FAILURE;
  }
  char *algo = argv[1];
  if (strcmp(algo, "dummy") == 0) {
    fprintf(stderr, "le test %s est vrai \n", argv[1]);
    return EXIT_SUCCESS;
  }
  fprintf(stderr, "le test %s est faux \n", argv[1]);
  bool ok = false;

  if (strcmp("game_delete", argv[1]) == 0)
    ok = test_game_delete();
  else if (strcmp("game_print", argv[1]) == 0)
    ok = test_game_print();
  else if (strcmp("game_copy", argv[1]) == 0)
    ok = test_game_copy();
  else if (strcmp("game_equal", argv[1]) == 0)
    ok = test_game_equal();
  else if (strcmp("game_get_current_nb_tents_all", argv[1]) == 0)
    ok = test_game_get_current_nb_tents_all();
  else if (strcmp("game_get_expected_nb_tents_all", argv[1]) == 0)
    ok = test_game_get_expected_nb_tents_all();
  else if (strcmp("game_is_over", argv[1]) == 0)
    ok = test_game_is_over();
  else if (strcmp("game_restart", argv[1]) == 0)
    ok = test_game_restart();
  else if (strcmp("game_nb_rows", argv[1]) == 0)
    ok = test_game_nb_rows();
  else if (strcmp("game_nb_cols", argv[1]) == 0)
    ok = test_game_nb_cols();
  else if (strcmp("game_load", argv[1]) == 0)
    ok = test_game_load();
  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n\n", argv[1]);
    return EXIT_FAILURE;
  }

  return EXIT_FAILURE;
}
