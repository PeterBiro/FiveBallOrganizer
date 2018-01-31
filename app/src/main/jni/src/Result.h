//
// Created by birop on 29/01/2018.
//

#ifndef FIVEBALLORGANIZER_RESULT_H
#define FIVEBALLORGANIZER_RESULT_H

#include <vector>

class Result {
public:
    enum state_enum {NORMAL, DRAW, TEAM_A_WON, TEAM_B_WON};

    Result()= default;
    Result(int a, int b);
    Result(state_enum state);
    ~Result()=default;


    void addScores(int a, int b);
    std::vector < std::pair<int, int> > getScores();
    void changeState(state_enum newState);

    state_enum getState();
private:
    state_enum state;
    std::vector < std::pair<int, int> > scores;
};


#endif //FIVEBALLORGANIZER_RESULT_H
