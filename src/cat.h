//
// Created by Ryan Levey on 9/11/2024.
//

#ifndef CAT_H
#define CAT_H
#include <string>

class Cat {
    public:
    Cat(int startX, int startY, std::string color);
    void move(std::string direction);
    void stomp();
    void powerUp();
    void displayStatus();

    int getX() const;
    int getY() const;
    int getPower() const;

    private:
    int x, y; //Current position
    int power; //The current power level of the cat
    std::string color; //The color of the cat
};

#endif //CAT_H
