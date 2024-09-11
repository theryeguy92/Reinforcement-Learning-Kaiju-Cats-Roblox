#include <iostream>

#include "grid.h"
#include "cat.h"
#include "dqn_agent.h"
#include <iostream>


//NOTE: Making GUI
int main() {
    Grid cityGrid(5,7); //Plug in the grid (5 rows and 7 columns)
    cityGrid.initializeGrid();

    Cat blueCat(0,0, "Blue");
    Cat redCat(2,0, "Red");
    Cat greenCat(4,0, "Green");

    DQNAgent agent; //Initalize the DQN agent

    for (int episode = 0; episode < 10000; episode++) {
        // Reset the positions and power for each episode

        for (int t = 0; t < 15; t++) {
            // Choose actions
            std::string actionBlue = agent.chooseAction(blueCat.getX(), blueCat.getY());
            std::string actionRed = agent.chooseAction(redCat.getX(), redCat.getY());
            std::string actionGreen = agent.chooseAction(greenCat.getX(), greenCat.getY());

            // Perform actions
            blueCat.move(actionBlue);
            redCat.move(actionRed);
            greenCat.move(actionGreen);

            // Calc the reward (NOTE: This is just a place holder)
            double rewardBlue = 0;
            double rewardRed = 0;
            double rewardGreen = 0;

            // Update Q-values
            agent.learn(blueCat.getX(), blueCat.getY(), actionBlue, rewardBlue, blueCat.getX(), blueCat.getY());
            agent.learn(redCat.getX(), redCat.getY(), actionRed, rewardRed, redCat.getX(), redCat.getY());
            agent.learn(greenCat.getX(), greenCat.getY(), actionGreen, rewardGreen, greenCat.getX(), greenCat.getY());


            // Decay epsilon for exploration/exploitation trade off
            agent.setEpsilon(std::max(0.1, agent.getEpsilon() - 0.001));

        }
        return 0;
    }
}