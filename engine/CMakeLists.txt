# cmake for uberchess_nn

cmake_minimum_required(VERSION 3.20)
project(uberchess_nn C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(ENGINE_SOURCES
    src/bitboard.c
    src/move.c
    src/pos.c
    src/movegen.c
    src/makemove.c
    src/zobrist.c
    src/tt.c
    src/eval_classic.c
    src/nnue.c
    src/search.c
    src/uci.c
    src/telemetry.c
)

add_library(engine_core STATIC ${ENGINE_SOURCES})
target_include_directories(engine_core PUBLIC ${ENGINE_INCLUDE_DIR})

add_executable(engine src/main.c)
target_link_libraries(engine PRIVATE engine_core)

add_executable(test_unit tests/test_unit.c)
target_link_libraries(test_unit PRIVATE engine_core)

add_executable(test_perft tests/test_perft.c)
target_link_libraries(test_perft PRIVATE engine_core)

add_executable(test_search tests/test_search.c)
target_link_libraries(test_search PRIVATE engine_core)

add_executable(bench_nps bench/bench_nps.c)
target_link_libraries(bench_nps PRIVATE engine_core)

add_executable(bench_eval bench/bench_eval.c)
target_link_libraries(bench_eval PRIVATE engine_core)

add_executable(bench_tt bench/bench_tt.c)
target_link_libraries(bench_tt PRIVATE engine_core)

enable_testing()
add_test(NAME test_unit COMMAND test_unit)
add_test(NAME test_perft COMMAND test_perft WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME test_search COMMAND test_search "startpos" "1")
