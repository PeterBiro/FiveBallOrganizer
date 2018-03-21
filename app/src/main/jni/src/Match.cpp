//
// Created by birop on 29/01/2018.
//

#include "Match.h"

Match::Match(Team * teamA, Team * teamB) : team_A(teamA), team_B(teamB) {

    A_ReadyFlag = false;
    B_ReadyFlag = false;

    A_NextWeek = false;
    B_NextWeek = false;

    results.clear();
}

void Match::addResult(std::string sport, int score_A, int score_B) {
    if (results.count(sport) == 0) {
        results[sport] = Result(score_A, score_B);
    } else {
        results[sport].addScores(score_A, score_B);
    }
}

void Match::addResult(std::string sport, Result::state_enum specialCase) {
    if (results.count(sport) == 0) {
        results[sport] = Result(specialCase);
    } else {
        results[sport].changeState(specialCase);
    }
}