//
// Created by birop on 29/01/2018.
//

#include "Result.h"

Result::Result() {
    state = NORMAL;
}

Result::Result(int a, int b) {
    Result();
    scores.push_back(std::pair(a,b));
}

void Result::changeState(state_enum newState) {
    state = newState;
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
