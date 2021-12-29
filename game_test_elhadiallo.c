#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_aux.h"
#include "game_ext.h"
#include "game_tools.h"

square t_square[64] = {
    EMPTY, EMPTY, EMPTY, EMPTY, TREE,  TREE,  EMPTY, EMPTY, TREE,  EMPTY, EMPTY,
    EMPTY, EMPTY, EMPTY, EMPTY, TREE,  EMPTY, EMPTY, EMPTY, EMPTY, TREE,  EMPTY,
    EMPTY, EMPTY, TREE,  EMPTY, EMPTY, EMPTY, EMPTY, TREE,  EMPTY, EMPTY, EMPTY,
    TREE,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, TREE,  EMPTY, EMPTY, EMPTY,
    TREE,  EMPTY, TREE,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
    EMPTY, TREE,  EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};

/* ********** USAGE ********** */

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <test_elhadiallo> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

bool test_game_set_square(void) {
  game g = game_default_solution();
  game_set_square(g, 0, 1, GRASS);
  game_set_square(g, 1, 0, TENT);
  if (game_get_square(g, 0, 1) != GRASS) {
    return false;
  }
  game_delete(g);
  return true;
}
/**************game_get_square*****************/
bool test_game_get_square() {
  game g = game_default();
  assert(g);
  uint count = 0;
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      if (game_get_square(g, i, j) != t_square[count]) {
        fprintf(stderr, "invalide content game \n");
        game_delete(g);
        return false;
      }
      if (game_get_square(g, i, j) < 0 || game_get_square(g, i, j) > 3) {
        fprintf(stderr, "unbound value of square \n");
        game_delete(g);
        return false;
      }
      count++;
    }
  }
  game_delete(g);
  return true;
}
/************game_set_expected_nb_tents_row**************/

bool test_game_set_expected_nb_tents_row() {
  game g = game_default();
  assert(g);
  uint count = 0;
  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      game_set_expected_nb_tents_row(g, i, j);
      if (game_get_expected_nb_tents_row(g, i) != j) {
        fprintf(stderr,
                "game_get_expected_nb_tents_row don't get the expected nb "
                "tents \n");
        game_delete(g);
        return false;
      }
      if (game_get_expected_nb_tents_row(g, i) > 8 ||
          game_get_expected_nb_tents_row(g, i) < 0) {
        fprintf(stderr,
                "game_get_expected_nb_tents_row return unbound value \n");
        game_delete(g);
        return false;
      }
      count++;
    }
  }
  game_delete(g);
  return true;
}

bool test_game_fill_grass_col(void) {
  game g = game_default();
  for (uint w = 0; w < 8; w++) {
    game_fill_grass_col(g, w);
    for (uint h = 0; h < 8; h++) {
      if (game_get_square(g, h, w) == EMPTY) {
        return false;
      }
    }
  }
  game_delete(g);
  return true;
}
/******************game_get_current_nb_tents_row******************/
bool test_game_get_current_nb_tents_row() {
  game g = game_default();
  assert(g);
  game gs = game_default_solution();
  assert(gs);
  // initialiser la ligne avec des tents
  game_set_square(g, 0, 0, TENT);
  game_set_square(g, 0, 1, TENT);
  game_set_square(g, 0, 2, TENT);
  game_set_square(g, 0, 7, TENT);
  cgame cg = g;
  assert(cg);
  // verifier si le nombre de tents correspond
  if (game_get_current_nb_tents_row(g, 0) != 4) {
    fprintf(stderr, "Error! the current number of tents is incorrect");
    game_delete(g);
    game_delete(gs);
    return false;
  }

  if (game_get_current_nb_tents_row(gs, 4) != 4) {
    fprintf(stderr, "Error! the current number of tents is incorrect");
    game_delete(g);
    game_delete(gs);
    return false;
  }
  game_delete(g);
  game_delete(gs);
  return true;
}

/******************game_default()********************/
bool test_game_default(void) {
  game g = game_default();
  if (g == NULL) {
    fprintf(stderr, " erreur game default \n");
    game_delete(g);
    return false;
  }

  for (uint i = 0; i < DEFAULT_SIZE; i++) {
    for (uint j = 0; j < DEFAULT_SIZE; j++) {
      if (game_get_square(g, i, j) == TENT ||
          game_get_square(g, i, j) == GRASS) {
        fprintf(stderr, "invalide content game \n");
        game_delete(g);
        return false;
      }
    }
  }

  game_delete(g);
  return true;
}
/******************game_default_solution()********************/
bool test_game_default_solution() {
  game g = game_default_solution();
  assert(g);

  for (int i = 0; i < DEFAULT_SIZE; i++) {
    for (int j = 0; j < DEFAULT_SIZE; j++) {
      if (game_get_square(g, i, j) == EMPTY) {
        fprintf(stderr, "Error! invalid content");
        game_delete(g);
        return false;
      }
    }
  }

  game_delete(g);
  return true;
}

/*****************game_fill_grass_row***************/
bool test_game_fill_grass_row() {
  game g = game_default();
  assert(g);

  game_fill_grass_row(g, 0);
  game_fill_grass_row(g, 2);
  game_fill_grass_row(g, 4);

  if (game_get_square(g, 0, 0) != GRASS) {
    fprintf(stderr, "Error! we have GRASS in this position");
    game_delete(g);
    return false;
  }

  if (game_get_square(g, 2, 3) != GRASS) {
    fprintf(stderr, "Error! we have GRASS in this position");
    game_delete(g);
    return false;
  }

  if (game_get_square(g, 4, 5) != GRASS) {
    fprintf(stderr, "Error! we have GRASS in this position");
    game_delete(g);
    return false;
  }

  game_delete(g);
  return true;
}

/****************** game_restart********************/
bool test_game_restart() {
  game g = game_default();
  game gn = game_default_solution();
  assert(g);
  assert(gn);

  game_restart(gn);
  return (game_equal(g, gn));
  uint count1 = 0;
  for (int i = 0; i < DEFAULT_SIZE; i++) {
    for (int j = 0; j < DEFAULT_SIZE; j++) {
      if (game_get_square(gn, i, j) != game_get_square(g, i, j)) {
        fprintf(stderr, "Error! countent is different");
        return false;
      }
      if (game_get_square(gn, i, j) == EMPTY ||
          game_get_square(gn, i, j) == TREE) {
        fprintf(stderr, "Error! invalid content");
        return true;
      }
      count1 = count1 + 1;
    }
  }

  return true;
}
/*******************game_new_empty**********************/
bool test_game_new_empty() {
  game g = game_new_empty();
  assert(g);

  for (int i = 0; i < DEFAULT_SIZE; i++) {
    for (int j = 0; j < DEFAULT_SIZE; j++) {
      if (game_get_square(g, i, j) != EMPTY) {
        fprintf(stderr, "Error! invalid content");
        game_delete(g);
        return false;
      }
      // verifier si le le nombre attendu de tentes pour chaque colonne est
      // different de zéro
      if (game_get_expected_nb_tents_col(g, j) != 0) {
        fprintf(stderr, "Error! invalid content");
        game_delete(g);
        return false;
      }
    }
    // verifier si le le nombre attendu de tentes pour chaque ligne est
    // different de zéro
    if (game_get_expected_nb_tents_row(g, i) != 0) {
      fprintf(stderr, "Error! invalid content");
      game_delete(g);
      return false;
    }
  }
  game_delete(g);
  return true;
}
/******************game_check_move********************/
bool test_game_check_move() {
  game g = game_default();

  game_set_square(g, 0, 1, TENT);   // LOSING
  game_set_square(g, 5, 2, TENT);   // LOSING
  game_set_square(g, 2, 3, TENT);   // REGULAR
  game_set_square(g, 2, 3, GRASS);  // REGULAR
  game_set_square(g, 0, 5, GRASS);  // ILLEGAL

  if (game_check_move(g, 0, 1, TENT) != LOSING) {
    game_delete(g);
    return false;
  }

  if (game_check_move(g, 2, 3, TENT) != REGULAR) {
    game_delete(g);
    return false;
  }

  if (game_check_move(g, 6, 3, GRASS) != REGULAR) {
    game_delete(g);
    return false;
  }

  if (game_check_move(g, 0, 5, GRASS) != REGULAR) {
    game_delete(g);
    return false;
  }

  if (game_check_move(g, 2, 5, TREE) != ILLEGAL) {
    game_delete(g);
    return false;
  }

  if (game_check_move(g, 4, 1, GRASS) != ILLEGAL) {
    game_delete(g);
    return false;
  }

  game_delete(g);
  return true;
}

/* **************** TEST IS WRAPPING ********************** */

bool test_iswrapping() {
  game g_wrap = game_new_empty_ext(4, 4, true, false);
  game g_no = game_new_empty_ext(4, 4, false, false);
  if (game_is_wrapping(g_no) || !game_is_wrapping(g_wrap)) {
    game_delete(g_no);
    game_delete(g_wrap);
    return false;
  }
  game_delete(g_no);
  game_delete(g_wrap);
  return true;
}
/* ******************* TEST ***************** */

bool test_game_new_empty_ext() {
  game g = game_new_empty_ext(3, 4, true, false);
  assert(g);

  for (uint i = 0; i < 3; i++) {
    for (uint j = 0; j < 4; j++) {
      if (game_get_square(g, i, j) != EMPTY) {
        game_delete(g);
        return false;
      }
    }
  }
  game_delete(g);
  return true;
}

/* ************* TEST **************  */

bool test_isdiagadj() {
  game g_diag = game_new_empty_ext(4, 4, false, true);
  game g_no = game_new_empty_ext(4, 4, false, false);
  if (game_is_diagadj(g_no) || !game_is_diagadj(g_diag)) {
    game_delete(g_no);
    game_delete(g_diag);
    return false;
  }
  game_delete(g_no);
  game_delete(g_diag);
  return true;
}

/* **************** **************** */
bool test_game_redo() { return true; }

/* ********************* ***************** */
bool test_game_undo() { return true; }
/***********************************************************/

/******************************game_new************************************/
bool test_game_new(void) {
  uint nbCol[8] = {4, 0, 1, 2, 1, 1, 2, 1};
  uint nbLig[8] = {3, 0, 4, 0, 4, 0, 1, 0};
  game g = game_new(t_square, nbLig, nbCol);
  for (uint x = 0; x < 8; x++) {
    for (uint y = 0; y < 8; y++) {
      if ((game_get_square(g, x, y) != 0 && game_get_square(g, x, y) != 1) ||
          game_get_square(g, x, y) == 2 || game_get_square(g, x, y) == 3) {
        //  game_delete(g);
        return false;
      }
    }
  }
  if (game_get_expected_nb_tents_all(g) != 12) {
    // game_delete(g);
    return false;
  }

  // game_delete(g);

  return true;
}
/******************game_save***********************************************/
bool test_game_save(void) {
  game g = game_default();
  assert(g);
  game_save(g, "game_default.txt");
  game g1 = game_load("game_default.txt");
  assert(g1);
  if (!game_equal(g, g1)) return false;
  game_delete(g);
  game_delete(g1);
  return true;
}
/**************************game_solve******************************/
bool test_game_solve() {
  game g = game_default();
  assert(g);
  if (!game_solve(g) && !game_is_over(g)) return false;
  return true;
}
/***********************game_nb_solutions***************************/
bool test_game_nb_solutions() {
  game g = game_default();
  assert(g);

  int nb_solutions1 = game_nb_solutions(g);

  if (nb_solutions1 != 1) return false;

  return true;
}
/* ********** MAIN ROUTINE ********** */

int main(int argc, char *argv[]) {
  if (argc == 1) usage(argc, argv);

  bool ok = false;

  if (strcmp("game_set_square", argv[1]) == 0)
    ok = test_game_set_square();
  else if (strcmp("game_get_square", argv[1]) == 0)
    ok = test_game_get_square();
  else if (strcmp("game_set_expected_nb_tents_row", argv[1]) == 0)
    ok = test_game_set_expected_nb_tents_row();
  else if (strcmp("game_fill_grass_col", argv[1]) == 0)
    ok = test_game_fill_grass_col();
  else if (strcmp("game_get_current_nb_tents_row", argv[1]) == 0)
    ok = test_game_get_current_nb_tents_row();
  else if (strcmp("game_fill_grass_row", argv[1]) == 0)
    ok = test_game_fill_grass_row();
  else if (strcmp("game_default", argv[1]) == 0)
    ok = test_game_default();
  else if (strcmp("game_default_solution", argv[1]) == 0)
    ok = test_game_default_solution();
  else if (strcmp("game_restart", argv[1]) == 0)
    ok = test_game_restart();
  else if (strcmp("game_new_empty", argv[1]) == 0)
    ok = test_game_new_empty();
  else if (strcmp("game_check_move", argv[1]) == 0)
    ok = test_game_check_move();
  /* else if (strcmp("game_is_over", argv[1]) == 0)
     ok = test_game_is_over();*/
  else if (strcmp("iswrapping", argv[1]) == 0)
    ok = test_iswrapping();
  else if (strcmp("game_new_empty_ext", argv[1]) == 0)
    ok = test_game_new_empty_ext();
  else if (strcmp("test_isdiagadj", argv[1]) == 0)
    ok = test_isdiagadj();
  else if (strcmp("game_undo", argv[1]) == 0)
    ok = test_game_undo();
  else if (strcmp("game_redo", argv[1]) == 0)
    ok = test_game_redo();
  else if (strcmp("game_new", argv[1]) == 0)
    ok = test_game_new_empty();
  else if (strcmp("game_save", argv[1]) == 0)
    ok = test_game_save();
  else if (strcmp("game_solve", argv[1]) == 0)
    ok = test_game_solve();
  else if (strcmp("game_nb_solutions", argv[1]) == 0)
    ok = test_game_nb_solutions();

  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n\n", argv[1]);
    return EXIT_FAILURE;
  }
}
