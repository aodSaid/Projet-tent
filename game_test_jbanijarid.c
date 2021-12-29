#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_aux.h"
#include "game_ext.h"
#include "game_tools.h"

void usage(char *commande) {
  fprintf(stderr, "Usage: %s <chaine> [<...>]\n", commande);
  exit(EXIT_FAILURE);
}

/* ********** game_set_expected_nb_tents_col ********** */

bool test_game_set_expected_nb_tents_col() {
  game g = game_default();
  assert(g);
  uint count = 0;
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      game_set_expected_nb_tents_col(g, i, j);
      if (game_get_expected_nb_tents_col(g, i) != j) {
        fprintf(stderr,
                "game_get_expected_nb_tents_col don't get the expected nb "
                "tents \n");
        game_delete(g);
        return false;
      }
      if (game_get_expected_nb_tents_col(g, i) > 8 ||
          game_get_expected_nb_tents_col(g, i) < 0) {
        fprintf(stderr,
                "game_get_expected_nb_tents_col return unbound value \n");
        game_delete(g);
        return false;
      }
      count++;
    }
  }
  game_delete(g);
  return true;
}

/* ********** game_get_current_nb_tents_col ********** */

bool test_game_get_current_nb_tents_col() {
  game g = game_default();
  assert(g);
  game gs = game_default_solution();
  assert(gs);
  // On initialize la premiere colonne avec des tents
  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 2, 0, TENT);
  game_set_square(g, 4, 0, TENT);
  game_set_square(g, 6, 0, TENT);

  // On verifie si le nombre de tents correspond
  if (game_get_current_nb_tents_col(g, 0) != 4) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    game_delete(gs);
    return false;
  }

  if (game_get_current_nb_tents_col(gs, 0) != 4) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    game_delete(gs);
    return false;
  }
  game_delete(g);
  game_delete(gs);
  return true;
}

/* ********** game_get_current_nb_tents_row ********** */

bool test_game_get_current_nb_tents_row() {
  game g = game_default();
  assert(g);
  game gs = game_default_solution();
  assert(g);
  // On initialize la premiere colonne avec des tents
  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 0, 2, TENT);
  game_set_square(g, 0, 3, TENT);
  game_set_square(g, 0, 6, TENT);
  cgame cg = g;
  assert(cg);
  // On verifie si le nombre de tents correspond
  if (game_get_current_nb_tents_row(g, 0) != 4) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    game_delete(gs);
    return false;
  }
  if (game_get_current_nb_tents_row(gs, 4) != 4) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    game_delete(gs);
    return false;
  }
  game_delete(g);
  game_delete(gs);
  return true;
}

/* ********** game_fill_grass_col ********** */

/*bool test_game_fill_grass_col() {
  game g = game_new_empty();
  assert(g);
  game_fill_grass_col(g, 0);
  game_fill_grass_col(g, 3);
  game_fill_grass_col(g, 5);
  if (game_get_square(g, 0, 0) != GRASS) {
    fprintf(stderr, "Error! GRASS must be here!\n");
    return false;
  }
  if (game_get_square(g, 2, 3) != GRASS) {
    fprintf(stderr, "Error! GRASS must be here!\n");
    return false;
  }
  if (game_get_square(g, 6, 5) != GRASS) {
    fprintf(stderr, "Error! GRASS must be here!\n");
    return false;
  }

  return true;
}*/

/* ********** game_get_expected_nb_tents_row ********** */

bool test_game_get_expected_nb_tents_row() {
  game g = game_default();
  assert(g);
  // On initialize les lignes avec un nombre de tents
  game_set_expected_nb_tents_row(g, 1, 3);
  game_set_expected_nb_tents_row(g, 3, 5);
  game_set_expected_nb_tents_row(g, 4, 6);

  // On verifie si le nombre de tents correspond
  if (game_get_expected_nb_tents_row(g, 1) != 3) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  if (game_get_expected_nb_tents_row(g, 3) != 5) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  if (game_get_expected_nb_tents_row(g, 4) != 6) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}

/* ********** game_get_expected_nb_tents_col ********** */

bool test_game_get_expected_nb_tents_col() {
  game g = game_default();
  assert(g);
  // On initialize les colonnes avec un nombre de tents
  game_set_expected_nb_tents_col(g, 1, 3);
  game_set_expected_nb_tents_col(g, 3, 5);
  game_set_expected_nb_tents_col(g, 4, 6);
  // On verifie si le nombre de tents correspond
  if (game_get_expected_nb_tents_col(g, 1) != 3) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  if (game_get_expected_nb_tents_col(g, 3) != 5) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  if (game_get_expected_nb_tents_col(g, 4) != 6) {
    fprintf(stderr, "Error! Incorrect number of tents\n");
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}

/* ********** game_get_expected_nb_tents_all ********** */

bool test_game_get_expected_nb_tents_all() {
  game g = game_default();
  assert(g);
  if (game_get_expected_nb_tents_all(g) != 0) {
    return false;
  }
  return true;
}

/* ********** game_equal ********** */

/*bool test_game_equal() {
  game g = game_default();
  game g2 = game_default();
  if (g == NULL || g2 == NULL) {
    fprintf(stderr, "Error! Invalid parameters\n");
    game_delete(g);
    return false;
  }
  if (!game_equal(g, g2)) {
    fprintf(stderr, "ERROR! game equal\n");
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}*/

/* ********** game_is_over ********** */

/*bool test_game_is_over() {
  game g = game_default();
  game gs = game_default_solution();
  assert(g);
  assert(gs);
  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 0, 3, TENT);
  game_set_square(g, 0, 6, TENT);
  game_set_square(g, 2, 0, TENT);
  game_set_square(g, 2, 3, TENT);
  game_set_square(g, 2, 5, TENT);
  game_set_square(g, 2, 7, TENT);
  game_set_square(g, 4, 0, TENT);
  game_set_square(g, 4, 2, TENT);
  game_set_square(g, 4, 4, TENT);
  game_set_square(g, 4, 6, TENT);
  game_set_square(g, 6, 0, TENT);
  if (game_get_current_nb_tents_all(g) != 12) {
    fprintf(stderr, "Error! false number of current tents\n");
    game_delete(g);
    game_delete(gs);
    return false;
  }
  if (game_get_current_nb_tents_all(gs) != 12) {
    free(g);
    free(gs);
    return false;
  }
  free(g);
  free(gs);
  return true;
}*/

/* ********** game_new_empty_ext ********** */
/*bool testv2_game_new_empty_ext() {
  game g = game_new_empty_ext(9, 10, true, true);
  assert(g);
  uint nb_rows = game_nb_rows(g);
  uint nb_cols = game_nb_cols(g);

  uint i, j;
  for (i = 0; i < nb_rows; i++) {
    for (j = 0; j < nb_cols; j++) {
      if (game_get_square(g, i, j) != EMPTY) {
        fprintf(stderr, "ERROR!! Invalid content!\n");
        game_delete(g);
        return false;
      }
      if (game_get_expected_nb_tents_col(g, j) != 0) {
        fprintf(stderr, "ERROR!! Invalid content!\n");
        game_delete(g);
        return false;
      }
    }

    if (game_get_expected_nb_tents_row(g, i) != 0) {
      fprintf(stderr, "ERROR! Invalid content!\n");
      game_delete(g);
      return false;
    }
  }
  game_delete(g);
  return true;
}*/

/* ********** game_new_ext ********** */
uint squares[8 * 8] = {
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};
uint nb_tents_row[8] = {0};
uint nb_tents_col[8] = {0};
/*
bool test_game_new_ext() {
  game g = game_new_ext(8, 8, squares, nb_tents_row, nb_tents_col, true, true);
  if (g == NULL) {
    return false;
  }
  return true;
}
*/

bool testv2_game_new_ext() {
  game g = game_new_ext(8, 8, squares, nb_tents_row, nb_tents_col, true, true);
  if (g == NULL) {
    return false;
  }
  if (game_nb_cols(g) != 8 || game_nb_rows(g) != 8) {
    return false;
  }
  for (uint i = 0; i < 8; i++) {
    for (uint j = 0; j < 8; j++) {
      if (game_get_square(g, i, j) != EMPTY) {
        game_delete(g);
        return false;
      }
    }
  }
  if (game_is_diagadj(g) != true || game_is_wrapping(g) != true) {
    game_delete(g);
    return false;
  }
  game_delete(g);
  return true;
}

////////// equal_ext ///////////
/*bool testv2_equal_ext() {
  game g1 = game_new_ext(8, 8, squares, nb_tents_row, nb_tents_col, true, true);
  game g2 = game_new_empty_ext(8, 8, true, true);
  bool resultat = game_equal(g1, g2);
  game_delete(g1);
  game_delete(g2);
  return resultat;
}*/

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
  if ((game_get_square(game_load1, 0, 0) != EMPTY) ||
      (game_get_square(game_load1, 1, 0) != TREE) ||
      (game_get_square(game_load1, 1, 2) != TREE)) {
    game_delete(game_load1);
    return false;
  }
  game_delete(game_load1);
  return true;
}

/* ********** main ********** */

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    usage(argv[0]);
  }

  if (strcmp(argv[1], "dummy") == 0) {
    printf("test %s: success\n", argv[1]);
    return EXIT_SUCCESS;
  }
  printf("test %s: failure\n", argv[1]);

  bool ok = false;

  if (strcmp("game_get_current_nb_tents_col", argv[1]) == 0)
    ok = test_game_get_current_nb_tents_col();
  if (strcmp("game_get_current_nb_tents_row", argv[1]) == 0)
    ok = test_game_get_current_nb_tents_row();
  /*else if (strcmp("game_fill_grass_col", argv[1]) == 0)
   ok = test_game_fill_grass_col();*/
  else if (strcmp("game_set_expected_nb_tents_col", argv[1]) == 0)
    ok = test_game_set_expected_nb_tents_col();
  else if (strcmp("game_get_expected_nb_tents_row", argv[1]) == 0)
    ok = test_game_get_expected_nb_tents_row();
  else if (strcmp("game_get_expected_nb_tents_col", argv[1]) == 0)
    ok = test_game_get_expected_nb_tents_col();
  else if (strcmp("game_get_expected_nb_tents_all", argv[1]) == 0)
    ok = test_game_get_expected_nb_tents_all();
  /*  else if (strcmp("game_equal", argv[1]) == 0)
      ok = test_game_equal();
    else if (strcmp("game_is_over", argv[1]) == 0)
      ok = test_game_is_over();*/
  else if (strcmp("game_new_ext", argv[1]) == 0)
    ok = testv2_game_new_ext();
  /* else if (strcmp("game_new_empty_ext", argv[1]) == 0)
     ok = testv2_game_new_empty_ext();
   else if (strcmp("game_equal_ext", argv[1]) == 0)
     ok = testv2_equal_ext();*/
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