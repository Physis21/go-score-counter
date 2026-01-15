// author name: Julien Dudas
//


#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>

// Stone values in an enum.
enum StoneVal {
    EMPTY=0,
    BLACK=1,
    WHITE=2
};

// Group values during scoring
// S_ prefix as in "Score".
enum ScoreAttribution {
    S_UNATTRIBUTED=0,
    S_BLACK=1,
    S_WHITE=2
};

// I use 'using' instead of 'typedef'. In general, 'using' is preferred because it supports templates.

using group_id_t = int;
using sline_t = std::vector<StoneVal>; // Line of stone values.
using sgrid2d_t = std::vector<sline_t>; // 2D grid of stone values.
using coord_t = std::vector<int>; // Should be 2D, but I can't make vectors of arrays. I could use boost, but this would be overkill.
using coordvec_t = std::vector<coord_t>; // Vector of coordinates.
// Map StoneVal to maps of group_id to coordinates.
using groups_by_val_t = std::map<std::pair<StoneVal, group_id_t>, coordvec_t>;
// Map ScoreAttribution to 
using score_attr_by_groups = std::map<std::pair<StoneVal, group_id_t>, std::map<ScoreAttribution, int>>;

// Converts an sgrid2d_t to a string.
std::string sgrid2d_tostring (sgrid2d_t sgrid_);

// Defines the dimensions of a Go board.
// The methods allow to extract information about the groups defined by stones on the board.
class GoBoard {
protected:
    // Size of the Go board.
    // Example: size = 19 refers to to 19*19 board.
    int size;
    // Square grid of stone values.
    // sgrid as in "stone grid".
    sgrid2d_t sgrid;
public:
    GoBoard(const int size_);
    ~GoBoard();

    // Setters and getters
    
    void set_size(const int size_);
    int get_size();
    void set_sgrid(const sgrid2d_t sgrid_);
    sgrid2d_t get_sgrid();
    // sets an empty sgrid.
    void set_sgrid_empty(); 
    // Sets a single value in an sgrid.
    void set_val_in_sgrid(const StoneVal value, const int i, const int j);
    // Returns vectors of coordinates grouped by their stone values.
    std::map<StoneVal, coordvec_t> get_val_groups(); 
    // Returns all the groups for each stone value.
    groups_by_val_t get_groups();
    // Returns the groups for white and black
    // Groups of EMPTY are attributed either UNATTRIBUTED, BLACK or WHITE.

    // Static functions

    // Checks if two coordinates are neighbours
    static bool are_neighbours(const coord_t c1, const coord_t c2);
};

class GoGame {
protected:
    int score = 0;
    GoBoard board;
};   
