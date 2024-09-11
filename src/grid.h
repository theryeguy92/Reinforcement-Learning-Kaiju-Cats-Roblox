//
// Created by Ryan Levey on 9/11/2024.
//

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>
#include "cat.h"

class Grid {
    public:
    Grid(int rows, int cols);
    void initializeGrid();
    void displayGrid();
    std::string getTileType(int row, int col);

    // Reward Function: Calcs the reward via the cat's position
    double getReward(Cat& cat);

    private:
    int rows;
    int cols;
    std::vector<std::vector<std::string>> gridData;
};
#endif

