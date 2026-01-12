#include <gtest/gtest.h>
#include <vector>
#include "go_board.h"

// For now don't do fixtures as I don't understand them.
class GoBoardTest : public testing::Test {
 protected:
    int small_size = 3;
    int sample_size = 19;
    GoBoard *small_b_ptr;
    GoBoard *b0_ptr;
 public:
    void SetUp() override { // Called at the start of each test.
        // Dynamically allocate
        small_b_ptr = new GoBoard(small_size);
        b0_ptr = new GoBoard(sample_size);
    }
    void TearDown() override { // Called at the end of each test.
        // Deallocate
        delete small_b_ptr;
        small_b_ptr = nullptr;
        delete b0_ptr;
        b0_ptr = nullptr;
    }
    // static void SetUpTestSuite(); // Called at the start of the test fixture.
    // static void TearDownTestSuite(); // Called after the end of the test fixture.
};

TEST(S2GRID, TOSTRING) {
    sgrid2d_t sample_sgrid = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLACK},
        {EMPTY, EMPTY, EMPTY},
    };
    std::string expected_string = "000\n001\n000\n";
    std::string converted_string = sgrid2d_tostring(sample_sgrid);
    EXPECT_EQ(expected_string, converted_string)
        << "Returned string is" << converted_string << std::endl;
}

// Check the setter and getter for goBoard.size work as intended.

TEST_F(GoBoardTest, InitAndGetSize) {
    EXPECT_EQ((*b0_ptr).get_size(), sample_size) << "Setting then getting GoBoard size gets unexpected value.";
}


// Check that GoBoard.set_grid_empty() initializes grid to empty.
TEST_F(GoBoardTest, SetGridEmpty) {
    sgrid2d_t small_grid_empty = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
    };
    (*small_b_ptr).set_sgrid_empty();
    EXPECT_EQ((*small_b_ptr).get_sgrid(), small_grid_empty);
}

TEST_F(GoBoardTest, SetValInGrid) {
    (*small_b_ptr).set_val_in_sgrid(BLACK, 1, 2);
    sgrid2d_t expected_grid = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, BLACK},
        {EMPTY, EMPTY, EMPTY},
    };
    EXPECT_EQ((*small_b_ptr).get_sgrid(), expected_grid);
}

TEST_F(GoBoardTest, GetValGroups) {
    sgrid2d_t sgrid_ = {
        {BLACK, BLACK, WHITE},
        {EMPTY, EMPTY, WHITE},
        {BLACK, WHITE, EMPTY}
    };
    (*small_b_ptr).set_sgrid(sgrid_);
    std::map<StoneVal, coordvec_t> expected_val_groups = {
        {BLACK, {{0, 0}, {0, 1}, {2, 0}}},
        {WHITE, {{0, 2}, {1, 2}, {2, 1}}},
        {EMPTY, {{1, 0}, {1, 1}, {2, 2}}}
    };
    EXPECT_EQ((*small_b_ptr).get_val_groups(), expected_val_groups)
        << "Value group returned is not as expected." << std::endl;
}

TEST_F(GoBoardTest, GetGroups) {
    sgrid2d_t sgrid_ = {
        {BLACK, BLACK, WHITE},
        {EMPTY, EMPTY, WHITE},
        {BLACK, WHITE, EMPTY}
    };
    (*small_b_ptr).set_sgrid(sgrid_);
    groups_by_val_t expected_groups = {
        {EMPTY, {
            {0, {{1, 0}, {1, 1}}},
            {1, {{2, 2},}}
        }},
        {WHITE, {
            {0, {{0, 2}, {1, 2}}},
            {1, {{2, 1},}}
        }},
        {BLACK, {
            {0, {{0, 0}, {0, 1}}},
            {1, {{2, 0},}}
        }}
    };
    ASSERT_EQ((*small_b_ptr).get_groups(), expected_groups)
        << "Result different from expected groups:\n";
}

TEST_F(GoBoardTest, AreNeighbours) {
    coord_t c1 = {3, 5};
    coord_t c2 = {2, 5};
    coord_t c3 = {3, 3};
    EXPECT_TRUE(GoBoard::are_neighbours(c1, c2));
    EXPECT_FALSE(GoBoard::are_neighbours(c1, c3));
}
