# CMake generated Testfile for 
# Source directory: /home/aodsaidou/Documents/s4/tents-a22b
# Build directory: /home/aodsaidou/Documents/s4/tents-a22b/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_game_save "./game_tools_test" "game_save_test")
set_tests_properties(test_game_save PROPERTIES  _BACKTRACE_TRIPLES "/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;22;add_test;/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;0;")
add_test(test_game_load "./game_tools_test" "game_load_test")
set_tests_properties(test_game_load PROPERTIES  _BACKTRACE_TRIPLES "/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;23;add_test;/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;0;")
add_test(test_game_solve "./game_tools_test" "game_solve_test")
set_tests_properties(test_game_solve PROPERTIES  _BACKTRACE_TRIPLES "/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;24;add_test;/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;0;")
add_test(test_game_nb_sol "./game_tools_test" "game_nb_solutions_test")
set_tests_properties(test_game_nb_sol PROPERTIES  _BACKTRACE_TRIPLES "/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;25;add_test;/home/aodsaidou/Documents/s4/tents-a22b/CMakeLists.txt;0;")
