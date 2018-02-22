//
// Created by birop on 19/02/2018.
//

#ifndef FIVEBALLORGANIZER_GFX_IFACE_H
#define FIVEBALLORGANIZER_GFX_IFACE_H

#include "KW_gui.h"
#include "KW_frame.h"
#include "KW_editbox.h"
#include "KW_label.h"
#include "KW_button.h"
#include "KW_renderdriver_sdl2.h"


class GFX_Iface {
public:
    GFX_Iface();
    ~GFX_Iface();

    static void RenderLoop();
    static void init();
    static KW_bool quit;
    static void OKClicked(KW_Widget * widget, int b);
    static SDL_Window * window;
    static SDL_Renderer * renderer;
    static KW_RenderDriver * driver;
    static KW_Surface * set;
    static KW_GUI * gui;
};


#endif //FIVEBALLORGANIZER_GFX_IFACE_H
