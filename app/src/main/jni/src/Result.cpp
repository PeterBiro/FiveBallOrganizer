//
// Created by birop on 29/01/2018.
//

#include "Result.h"


Result::Result(int a, int b) {
    state = NORMAL;
    scores.push_back(std::pair(a,b));
}

Result::Result(state_enum state){
    this->state = state;
}

state_enum Result::getState() {
    return state;
}

void Result::addScores(int a, int b) {
    scores.push_back(std::pair(a,b));
}

std::vector <std::pair<int, int>> void Result::getScores() {
    return scores;
}
