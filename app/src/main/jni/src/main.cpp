/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and, strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "SDL_Init.h"
#include "../rapidjson/document.h"



int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        SDL_Log( "Failed to initialize!\n" );
    }
    else
    {
       SDL_Log("SDL started\n");
    }
    SDL_Delay(3000);
    //Free resources and close SDL
    close();

    return 0;
}
