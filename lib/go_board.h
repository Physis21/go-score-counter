// author name: Julien Dudas
//


#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>

enum StoneVal {
    EMPTY,
    BLACK,
    WHITE
};

// sgrid as in "Stone Grid".
// I use 'using' instead of 'typedef'. In general, 'using' is preferred because it supports templates.
using group_id_t = int;
using sline_t = std::vector<StoneVal>; // Line of stone values.
using sgrid2d_t = std::vector<sline_t>; // 2D grid of stone values.
using coord_t = std::vector<int>; // Should be 2D, but I can't make vectors of arrays. I could use boost, but this would be overkill.
using coordvec_t = std::vector<coord_t>;
using groups_by_val_t = std::map<StoneVal, std::map<group_id_t, coordvec_t>>;

std::string sgrid2d_tostring (sgrid2d_t sgrid_);

// Defines the dimensions of the Go board.
class GoBoard {
protected:
    int size;
    sgrid2d_t sgrid;
public:
    GoBoard(const int size_);
    ~GoBoard();

    // Setters and getters
    void set_size(const int size_);
    int get_size();
    void set_sgrid(const sgrid2d_t sgrid_);
    void set_sgrid_empty();
    sgrid2d_t get_sgrid();
    void set_val_in_sgrid(const StoneVal value, const int i, const int j);

    std::map<StoneVal, coordvec_t> get_val_groups();
    groups_by_val_t get_groups();

    // Static functions
    static bool are_neighbours(const coord_t c1, const coord_t c2);
};

class GoGame {
protected:
    int score = 0;
    GoBoard board;
};   
