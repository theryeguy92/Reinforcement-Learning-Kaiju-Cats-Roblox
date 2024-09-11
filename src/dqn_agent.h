//
// Created by Ryan Levey on 9/11/2024.
//

#ifndef DQN_AGENT_H
#define DQN_AGENT_H

#include <map>
#include <vector>
#include <string>

class DQNAgent {
    public:
    DQNAgent();
    std::string chooseAction(int x, int y);
    void learn(int x, int y, std::string action, double reward, int newX, int newY);

    // Getter and setter for epsilon
    double getEpsilon() const { return epsilon; }
    void setEpsilon(double newEpsilon) { epsilon = newEpsilon; }

    private:
    double gamma;
    double epsilon;
    double alpha;
    std::map<std::pair<int, int>, std::vector<double>> qTable;

    int actionIndex(std::string action);
    std::string maxQAction(std::pair<int, int> state);

};

#endif //DQN_AGENT_H
