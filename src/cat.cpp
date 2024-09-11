//
// Created by Ryan Levey on 9/11/2024.
//

#include "cat.h"
#include <iostream>
using namespace std;

Cat::Cat(int startX, int StartY, string color) : x(startX), y(StartY), color(color) {
    power = 1000;
}

// Getter for X-coordinate
int Cat::getX() const {
    return x;
}

// Getter for Y-coordinate
int Cat::getY() const {
    return y;
}

// Getter for power
int Cat::getPower() const {
    return power;
}
// Setter for power
void Cat::setPower(int newPower) {
    power = newPower;
}

// Getter for color
std::string Cat::getColor() const {
    return color;  // Return the color of the cat
}

void Cat::move(string direction) {
    if(direction == "North") x--;
    else if(direction == "South") x++;
    else if(direction == "East") y++;
    else if (direction == "West") y--;
}

void Cat::stomp() {
    cout << color << " Cat Stomps on the current tile." << endl;
}

void Cat::powerUp() {
    power +=1000;
    cout << color << " Cat powers up! New power: " << power << endl;
}

void Cat::displayStatus() {
    cout << color << " Cat - Position: (" << x << ", " << y <<"), Power: " << power <<endl;
}
