enable_testing()

# Logic for the go board
add_library(go_board)

target_sources(go_board
  PRIVATE 
    go_board.cpp

  PUBLIC
    FILE_SET HEADERS
    FILES
      go_board.h
)

# Tests

# Test the methods in go_board.cpp
add_executable(go_board_test go_board_test.cpp)

target_link_libraries(go_board_test
  PRIVATE
    go_board
  PUBLIC
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(go_board_test)

