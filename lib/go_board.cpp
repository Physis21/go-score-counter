#include <string>
#include <vector>
#include <assert.h>
#include "go_board.h"

std::string sgrid2d_tostring(sgrid2d_t sgrid_) {
    std::string output = "";
    for (sline_t sline : sgrid_) {
        for (StoneVal stone : sline) {
            output += std::to_string(stone);
        }
        output += "\n";
    }
    return output;
}

GoBoard::GoBoard(int size_) {
    set_size(size_); 
    set_sgrid_empty();
}

void GoBoard::set_size(int size_) {
    size = size_;
}

int GoBoard::get_size() {
    return size;
}

void GoBoard::set_sgrid(sgrid2d_t sgrid_) {
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

void GoBoard::set_val_in_sgrid(StoneVal value, int i, int j) {
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
    groups_by_val_t output = {
        {EMPTY, {}},
        {BLACK, {}},
        {WHITE, {}}
    };
    for (const auto my_pair : val_groups) {
        StoneVal stone_val = my_pair.first;
        coordvec_t cfsv = my_pair.second; // Coordinates for a stone value.
        int cepi; // current evaluated position index.
        coord_t cep; // current evaluated position.
        group_id_t group_id = -1;
        for (cepi = 0; cepi < cfsv.size(); cepi++) {
            // TODO: The way I define groups is not right.
            // TODO: The last value ({2,2}) in test is never explored.
            if (std::find(coords_already_in_group.begin(), coords_already_in_group.end(), cfsv[cepi]) != coords_already_in_group.end()) {
                // coords_already_in_group contains cep.
                continue; // look at next value.
            } else {
                group_id++; // Recognize that this is a different group, and create a new one.
            }
            // Simplest (and maybe most efficient) way to iterate on cfsv at all indexes except cepi.
            for (int i = cepi; i < cfsv.size(); i++) {
                if (
                    (cfsv[cepi][0] == cfsv[i][0] && ((cfsv[cepi][1] == cfsv[i][1] + 1) || (cfsv[cepi][1] == cfsv[i][1] - 1))) ||
                    (cfsv[cepi][1] == cfsv[i][1] && ((cfsv[cepi][0] == cfsv[i][0] + 1) || (cfsv[cepi][0] == cfsv[i][0] - 1)))
                ) {
                    output[stone_val][group_id].push_back(cfsv[i]);
                } 
            }
            for (int i = cepi; i >= 0; i--) {
                if (
                    (cfsv[cepi][0] == cfsv[i][0] && ((cfsv[cepi][1] == cfsv[i][1] + 1) || (cfsv[cepi][1] == cfsv[i][1] - 1))) ||
                    (cfsv[cepi][1] == cfsv[i][1] && ((cfsv[cepi][0] == cfsv[i][0] + 1) || (cfsv[cepi][0] == cfsv[i][0] - 1)))
                ) {
                    output[stone_val][group_id].push_back(cfsv[i]);
                } 
            }
        }
    }
    return output;
}

// TODO
// coordvec_t GoBoard::get_group(int i, int j) {
//     coordvec_t group_stone_coords;
//     group_stone_coords.push_back({i, j});
//     StoneVal ref_stone = sgrid.at(i).at(j);
//     if (ref_stone == EMPTY) { // If the coordinates point to an empty space, return only them.
//         return group_stone_coords;
//     }
//     for (int i1 = i; i1 < size; i1++) {
//         for (int i2 = j+1; i2 < size; i2++) {
//             StoneVal current_stone = sgrid.at(i1).at(i2);
//             if (current_stone == ref_stone) {
//                 // TEMP: for now, this returns all stones with same value.
//                 group_stone_coords.push_back({i1, i2}); 
//             }
//         }
//     }
//     return group_stone_coords;
// }
