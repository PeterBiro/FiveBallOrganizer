#include "JsonInterface.h"
#include "GFX_Iface.h"


int main(int argc, char ** argv) {
    SDL_Log("myLog: Main is running");
    GFX_Iface::init();

    while (!SDL_QuitRequested() && !GFX_Iface::quit) {
        GFX_Iface::RenderLoop();
    }
    return 0;
}