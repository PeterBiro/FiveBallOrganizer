//
// Created by birop on 22/03/2018.
//

#include "MainFrame.h"


void MainFrame::run() {
    Globals globals;

    SDL_Log("myLog: Main is running");
    GFX_Iface::init(&globals);

    JsonInterface myParser(&globals);
    myParser.LoadTeams("json/sampleteams.json");

    while (!SDL_QuitRequested() && !GFX_Iface::quit) {
        GFX_Iface::RenderLoop();
    }
}
