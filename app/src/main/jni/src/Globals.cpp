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

Team * Globals::getTeamByTeamName(std::string teamName) {
    for (auto team : teams) {
        if (team->getName() == teamName) return team;
    }
    return nullptr;
}