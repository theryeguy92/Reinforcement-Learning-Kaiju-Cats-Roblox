//
// Created by Ryan Levey on 9/11/2024.
//

#include "grid.h"
#include <iostream>

using namespace std;

// Construct: Init the grid with rows and columns
Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {
    gridData.resize(rows, vector<string>(cols, "Blank"));
}

// Init method: Grid with user input
void Grid::initializeGrid() {
    cout << "Enter grid data (e.g., 'High Value Building', 'Blank', 'Mud') for each tile: " << endl;
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            string inputTile;
            cout <<"Tile [" << i <<"][" << j << "]: ";
            cin >> ws; //Clear input buffer
            getline(cin, inputTile);
            gridData[i][j] = inputTile;
        }
    }
}

// Display grid for debugging

void Grid::displayGrid() {
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j <cols; j++) {
            cout << gridData[i][j] << "\t";
        }
        cout << endl;
    }
}

// Return type of tile at a specific location

string Grid::getTileType(int row, int col) {
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        return gridData[row][col];
    }
    return "N/A"; //Only if the position is invalid
}

// Reward function: Calc the reward via the cat's current position
double Grid::getReward(Cat& cat) {
    // Get the current tile type where the cat is standing
    string currentTile = getTileType(cat.getX(), cat.getY());

    if (currentTile == "Low Value Building") {
        cat.setPower(cat.getPower() + 250);
        cout << cat.getColor() << " Cat destroys a Low Value Building. Power increased to " << cat.getPower() << endl;
        return 250;
    } else if (currentTile == "High Value Building") {
        cat.setPower(cat.getPower() + 500);
        cout << cat.getColor() << " Cat destroys a High Value Building. Power increased to " << cat.getPower() << endl;
        return 500;
    } else if (currentTile == "Power Plant") {
        cat.setPower(cat.getPower() * 2);
        cout << cat.getColor() << " Cat destroys a Power Plant. Power doubled to " << cat.getPower() << endl;
        return cat.getPower();
    } else if (currentTile == "Spikes") {
        cat.setPower(cat.getPower() / 2);
        cout << cat.getColor() << " Cat steps on Spikes. Power halved to " << cat.getPower() << endl;
        return -cat.getPower() / 2;
    } else if (currentTile == "Mud") {
        cout << cat.getColor() << " Cat gets stuck in Mud for 1 turn." << endl;
        return -100; // Penalty for getting stuck
    }

    return 0;


}



/*string Grid::getTileType(int row, int col) {
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        return gridData[row][col];
    }
    return "N/A"; //Invalid Tile

}*/


// void Grid::initializeGrid() {
//     // Implimentation of grid
// }

// void Grid::displayGrid() {
//     // Implimentation of displaying the grid
// }

/*string Grid::getTileType(int row, int col) {
    if(row >= 0 && row < rows && col >= 0 && col < cols) {
        return gridData[row][col];
    }
    return "N/A"; //Invalid Tile

}*/