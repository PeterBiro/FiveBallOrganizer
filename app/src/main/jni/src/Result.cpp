//
// Created by birop on 29/01/2018.
//

#include "Result.h"


Result::Result(int a, int b) {
    state = NORMAL;
    scores.push_back(std::make_pair(a,b));
}

Result::Result(state_enum state){
    this->state = state;
}

Result::state_enum Result::getState() {
    return state;
}

void Result::addScores(int a, int b) {
    scores.push_back(std::make_pair(a,b));
}

std::vector < std::pair<int, int> > Result::getScores() {
    return scores;
}

void Result::changeState(state_enum newState) {
    state = newState;
}
