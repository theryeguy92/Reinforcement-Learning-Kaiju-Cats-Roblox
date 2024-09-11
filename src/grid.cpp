//
// Created by Ryan Levey on 9/11/2024.
//

#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    gridData.resize(rows, vector<string>(cols, "Blank"));
}

void Grid::initializeGrid() {
    // Implimentation of grid
}

void Grid::displayGrid() {
    // Implimentation of displaying the grid
}

string Grid::getTileType(int row, int col) {
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        return gridData[row][col];
    }
    return "N/A"; //Invalid Tile

}
