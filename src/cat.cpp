//
// Created by Ryan Levey on 9/11/2024.
//

#include "cat.h"
#include <iostream>
using namespace std;

Cat::Cat(int startX, int StartY, string color) : x(startX), y(StartY), color(color) {
    power = 1000;
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
