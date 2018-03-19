//
// Created by birop on 19/03/2018.
//

#include "Globals.h"

void Globals::addTeam(Team *team) {
    teams.emplace_back(team);
}

std::vector <Team*>* Globals::getAllTeams() {
    return &teams;
}