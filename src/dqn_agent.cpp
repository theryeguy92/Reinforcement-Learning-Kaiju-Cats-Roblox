//
// Created by Ryan Levey on 9/11/2024.
//
#include "dqn_agent.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

DQNAgent::DQNAgent() {
    gamma = 0.99;
    epsilon = 1.0;
    alpha = 0.01;
    srand(time(0));
}

std::string DQNAgent::chooseAction(int x, int y) {
    if ((rand() % 100) < (epsilon * 100)) {
        std::vector<std::string> actions = {"North", "South", "East", "West", "Stomp", "PowerUp"};
        return actions[rand() % actions.size()];
    } else {
        std::pair<int, int> state = {x, y};
        return maxQAction(state);
    }
}

std::string DQNAgent::maxQAction(std::pair<int, int> state) {
    if (qTable.find(state) == qTable.end()) {
        return "North"; //Default action
    }

    std::vector<double> qValues = qTable[state];
    std::vector<std::string> actions = {"North", "South", "East", "West", "Stomp", "PowerUp"};
    int maxIndex = std::distance(qValues.begin(), std::max_element(qValues.begin(), qValues.end()));
    return actions[maxIndex];
}

void DQNAgent::learn(int x, int y, std::string action, double reward, int newX, int newY) {
    std::pair<int, int> state = {x, y};
    std::pair<int, int> newState = {newX, newY};

    double qOld = qTable[state][actionIndex(action)];
    double qMaxNew = *std::max_element(qTable[newState].begin(), qTable[newState].end());
    qTable[state][actionIndex(action)] = qOld + alpha * (reward + gamma * qMaxNew - qOld);
}

int DQNAgent::actionIndex(std::string action){
    if (action == "North") return 0;
    if (action == "South") return 1;
    if (action == "East") return 2;
    if (action == "West") return 3;
    if (action == "Stomp") return 4;
    return 5; // PowerUp

}