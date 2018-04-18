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
#include "Globals.h"


class JsonInterface {
public:
    JsonInterface(Globals * globals);
    ~JsonInterface()= default;

    void LoadTeams(std::string path);

private:
    Globals * globals = nullptr;

};


#endif //FIVEBALLORGANIZER_JSONINTERFACE_H
