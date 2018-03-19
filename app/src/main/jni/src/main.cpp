#include "GFX_Iface.h"


int main(int argc, char ** argv) {
    Globals globals;

    SDL_Log("myLog: Main is running");
    GFX_Iface::init(&globals);

    JsonInterface myParser(&globals);
    myParser.LoadTeams("json/sampleteams.json");

    while (!SDL_QuitRequested() && !GFX_Iface::quit) {
        GFX_Iface::RenderLoop();
    }
    return 0;
}