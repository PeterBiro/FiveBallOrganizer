//
// Created by birop on 19/03/2018.
//

#ifndef FIVEBALLORGANIZER_GLOBALS_H
#define FIVEBALLORGANIZER_GLOBALS_H


#include <vector>
#include "Team.h"

class Globals {
public:
    Globals()= default;
    ~Globals()= default;

    void addTeam(Team * team);
    std::vector <Team*> * getAllTeams();

private:
   std::vector <Team*>teams ;
};


#endif //FIVEBALLORGANIZER_GLOBALS_H
