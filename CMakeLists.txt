cmake_minimum_required(VERSION 3.29)
project(ReinforcementLearningKaijuCatsOptimizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(ReinforcementLearningKaijuCatsOptimizer src/main.cpp
        src/grid.h
        src/grid.cpp
        src/cat.h
        src/cat.cpp
        src/dqn_agent.h
        src/dqn_agent.cpp)
