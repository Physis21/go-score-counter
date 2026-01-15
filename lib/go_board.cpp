#include <cstdio>
#include <string>
#include <vector>
#include <assert.h>
#include "go_board.h"

std::string sgrid2d_tostring(const sgrid2d_t sgrid_) {
    std::string output = "";
    for (sline_t sline : sgrid_) {
        for (StoneVal stone : sline) {
            output += std::to_string(stone);
        }
        output += "\n";
    }
    return output;
}

GoBoard::GoBoard(const int size_) {
    set_size(size_); 
    set_sgrid_empty();
}

GoBoard::~GoBoard() {

}

void GoBoard::set_size(const int size_) {
    size = size_;
}

int GoBoard::get_size() {
    return size;
}

void GoBoard::set_sgrid(const sgrid2d_t sgrid_) {
    set_sgrid_empty();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sgrid.at(i).at(j) = sgrid_.at(i).at(j);
        }
    }
}

void GoBoard::set_sgrid_empty() {
    // assert(&size != nullptr);
    sgrid2d_t sgrid_empty(
        size,
        std::vector<StoneVal>(size, EMPTY)
    );
    sgrid = sgrid_empty;
}

sgrid2d_t GoBoard::get_sgrid() {
    return sgrid;
}

void GoBoard::set_val_in_sgrid(const StoneVal value, const int i, const int j) {
    sgrid.at(i).at(j) = value;
}

std::map<StoneVal, coordvec_t> GoBoard::get_val_groups() {
    std::map<StoneVal, coordvec_t> output = {
        {EMPTY, {}},
        {BLACK, {}},
        {WHITE, {}}
    };
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            output[sgrid[i][j]].push_back({i, j}) ;
        }
    }
    return output;
}

groups_by_val_t GoBoard::get_groups() {
    std::map<StoneVal, coordvec_t> val_groups = get_val_groups();
    coordvec_t coords_already_in_group = {};
    groups_by_val_t output = {};
    for (const auto my_pair : val_groups) {
        StoneVal stone_val = my_pair.first;
        coordvec_t cfsv = my_pair.second; // Vector of coordinates for a stone value.
        int cevi; // current evaluated vector index.
        group_id_t group_id = -1;
        for (cevi = 0; cevi < cfsv.size(); cevi++) {
            // Check if cfsv[cevi] is in coords_already_in_group.
            if (std::find(coords_already_in_group.begin(), coords_already_in_group.end(), cfsv[cevi]) != coords_already_in_group.end()) {
                continue; // look at next value.
            } else {
                group_id++; // Recognize that this is a different group, and create a new one.
                output.insert({{stone_val, group_id}, {}});
                output[{stone_val, group_id}].push_back(cfsv[cevi]);
                coords_already_in_group.push_back(cfsv[cevi]);
            }
            // Simplest (and maybe most efficient) way to iterate on cfsv at all indexes except cevi.
            for (int i = cevi; i < cfsv.size(); i++) {
                if (are_neighbours(cfsv[cevi], cfsv[i])) {
                    output[{stone_val, group_id}].push_back(cfsv[i]);
                    coords_already_in_group.push_back(cfsv[i]); // This stone is now already categorized in a group.
                }
                            }
            for (int i = cevi; i >= 0; i--) {
                if (are_neighbours(cfsv[cevi], cfsv[i])) {
                    output[{stone_val, group_id}].push_back(cfsv[i]);
                    coords_already_in_group.push_back(cfsv[i]); // This stone is now already categorized in a group.
                }
            }
        }
    }
    return output;
}

bool GoBoard::are_neighbours(const coord_t c1, const coord_t c2) {
    if (
        (c1[0] == c2[0] && ((c1[1] == c2[1] + 1) || c1[1] == c2[1] - 1)) ||
        (c1[1] == c2[1] && ((c1[0] == c2[0] + 1) || c1[0] == c2[0] - 1))
    ) {
        return true;
    } else {
        return false;
    }
};
