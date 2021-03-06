//
// Created by birop on 16/01/2018.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "JsonInterface.h"


JsonInterface::JsonInterface(Globals * globals_ptr) {
    SDL_Log("JSON: JsonInterface Constructor is running.\n" );
    globals = globals_ptr;
}

void JsonInterface::LoadTeams(std::string path) {
    SDL_Log("JSON: JsonInterface LoadTeams is running.\n" );

    SDL_RWops *io = SDL_RWFromFile(path.c_str(), "r");
    if (io != NULL) {
        size_t fileSize = SDL_RWseek(io, 0, RW_SEEK_END);
        //TODO Check if fileSize == -1
        SDL_RWseek(io, 0, RW_SEEK_SET);
        char data[fileSize];
        SDL_RWread(io, data, 1, fileSize);
        std::string fileContent = data;
        SDL_Log("JSON: %s\n", fileContent.c_str());
        SDL_RWclose(io);

        rapidjson::Document document;
        document.Parse(fileContent.c_str());
        SDL_Log("JSON: documet parse is done\n");
        for(rapidjson::Value::ConstValueIterator itr = document.Begin(); itr != document.End(); ++itr) {
            auto member = itr->GetObject();
            Team * newTeam = new Team(member["name"].GetString(), member["category"].GetString());
            SDL_Log("New team created: %s\n", newTeam->getName().c_str());
            globals->addTeam(newTeam);
        }
    } else {
        //TODO FileOpenError
        SDL_Log("JSON: Can't open %s.\n", path.c_str() );
    }
}