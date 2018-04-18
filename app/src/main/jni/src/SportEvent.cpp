//
// Created by birop on 22/03/2018.
//

#include "SportEvent.h"

SportEvent::SportEvent(std::string sportsToInit[5], enum eventType eventTp) : eventType(eventTp) {
    for (int i = 0; i < 5; ++i) {
        sports[i] = sportsToInit[i];
    }
}

void SportEvent::start() {
    Globals globals;

    SDL_Log("myLog: Main is running");
    GFX_Iface::init(&globals);

    JsonInterface myParser(&globals);
    myParser.LoadTeams("json/sampleteams.json");

    while (!SDL_QuitRequested() && !GFX_Iface::quit) {
        GFX_Iface::RenderLoop();
    }

}
