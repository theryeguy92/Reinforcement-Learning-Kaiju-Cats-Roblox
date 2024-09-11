//
// Created by Ryan Levey on 9/11/2024.
//

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

class Grid {
    public:
    Grid(int rows, int cols);
    void initializeGrid();
    void displayGrid();
    std::string getTileType(int row, int col);

    private:
    int rows;
    int cols;
    std::vector<std::vector<std::string>> gridData;
};
#endif

