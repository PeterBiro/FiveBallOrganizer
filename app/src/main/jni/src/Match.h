//
// Created by birop on 29/01/2018.
//

#ifndef FIVEBALLORGANIZER_MATCH_H
#define FIVEBALLORGANIZER_MATCH_H

#include <map>
#include "Team.h"
#include "Result.h"

class Match {
public:
    Match(Team * teamA, Team * teamB);
    ~Match()= default;

    void addResult(std::string sport, int score_A, int score_B);
    void addResult(std::string sport, Result::state_enum specialCase);

private:
    Team * team_A;
    Team * team_B;

    std::map <std::string, Result> results;

    bool A_ReadyFlag;
    bool B_ReadyFlag;
    bool A_NextWeek;
    bool B_NextWeek;

};


#endif //FIVEBALLORGANIZER_MATCH_H
