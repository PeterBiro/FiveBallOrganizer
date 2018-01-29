//
// Created by birop on 16/01/2018.
//

#ifndef FIVEBALLORGANIZER_JSONINTERFACE_H
#define FIVEBALLORGANIZER_JSONINTERFACE_H

#include <string>
#include <vector>
#include "../rapidjson/document.h"
#include "Team.h"
#include "SDL.h"


class JsonInterface {
public:
    JsonInterface();
    ~JsonInterface()= default;

    std::vector <Team>* LoadTeams(std::string path);

private:

};


#endif //FIVEBALLORGANIZER_JSONINTERFACE_H
