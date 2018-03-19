//
// Created by birop on 19/02/2018.
//

#include <src/KW_widget_internal.h>
#include "GFX_Iface.h"


SDL_Window * GFX_Iface::window = NULL;
SDL_Renderer * GFX_Iface::renderer = NULL;
KW_RenderDriver * GFX_Iface::driver = NULL;
KW_Surface * GFX_Iface::set = NULL;
KW_GUI * GFX_Iface::gui = NULL;
KW_bool GFX_Iface::quit = KW_FALSE;


GFX_Iface::GFX_Iface() {
}

void GFX_Iface::init(){

    SDL_Log("myLog: gfx - init started");


    const int DISPLAY_HEIGHT = 1440;
    const int DISPLAY_WIDTH = 2048;

    /* Initialize SDL */
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Log("myLog: SDL initialized");

    KW_Rect windowrect = { 0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT };
    SDL_CreateWindowAndRenderer(windowrect.w, windowrect.h, 0, &window, &renderer);
    SDL_Log("myLog: window and renderer created");
    SDL_SetRenderDrawColor(renderer, 100, 100, 200, 1);

    /* Initialize KiWi */
    SDL_Log("myLog: Before KiWi initialization");
    driver = KW_CreateSDL2RenderDriver(renderer, window);
    set = KW_LoadSurface(driver, "KiWi-example/tileset.png");
    gui = KW_Init(driver, set);

    SDL_Log("myLog: and after KiWi initialization");

    /* Create the left frame for matches */
    KW_Rect leftFrameRect = { .x = 0, .y = 0, .w = DISPLAY_WIDTH/2, .h = DISPLAY_HEIGHT };
    KW_RectVerticallyCenterInParent(&windowrect, &leftFrameRect );
    KW_Widget * leftFrame = KW_CreateFrame(gui, NULL, &leftFrameRect);

    SDL_Log("myLog: Left frame created");

    /* Create add new match button */

    KW_Rect addMatchRect = {.x = 120, .y = 120, .w = 150, .h = 150};
    KW_Widget * addMatchFrame = KW_CreateButtonAndLabel(gui, leftFrame, "Add new match", &addMatchRect);
    KW_AddWidgetMouseDownHandler(addMatchFrame, addMatchClicked);
    SDL_Log("myLog: add new match button event handler added");


    SDL_Log("myLog: All labels created");

    /* Create the right frame for fields*/
    KW_Rect rightFrameRect = { .x = DISPLAY_WIDTH/2, .y = 0, .w = DISPLAY_WIDTH/2, .h = DISPLAY_HEIGHT };
    KW_RectVerticallyCenterInParent(&windowrect, &rightFrameRect );
    KW_Widget * rightFrame = KW_CreateFrame(gui, NULL, &rightFrameRect);

    SDL_Log("myLog: Right frame created");

    KW_Rect buttonrect = { .x = 250, .y = 170, .w = 40, .h = 40 };
    KW_Widget * okbutton = KW_CreateButtonAndLabel(gui, rightFrame, "OK", &buttonrect);

    SDL_Log("myLog: OK button created");

    KW_bool quit = KW_FALSE;

    KW_AddWidgetMouseDownHandler(okbutton, OKClicked);
    SDL_Log("myLog: OKClicked event handler added");

}

GFX_Iface::~GFX_Iface() {
    /* free stuff */
    KW_Quit(gui);
    KW_ReleaseSurface(driver, set);
    KW_ReleaseRenderDriver(driver);
    SDL_Quit();
}

/* Callback for when the OK button is clicked */

void GFX_Iface::OKClicked(KW_Widget * widget, int b) {
    SDL_Log("myLog: OK button clicked - quiting");
    quit = KW_TRUE;
}

void GFX_Iface::firstTeamSelectedForMatch(KW_Widget * widget, int b) {
    SDL_Log("myLog: First team selected (at least clicked ;) )");
    auto selectedTeamName = KW_GetWidgetUserData(widget);
    SDL_Log("myLog: userData of widget: %s",(char*)selectedTeamName);

    KW_DestroyWidget(widget->parent, 1);

    //Show new frame
    KW_Rect centerRect = {.x = 5, .y = 5, .w = 2038, .h = 1430};
    KW_Widget * addNewMatchFrame = KW_CreateFrame(gui, NULL, &centerRect);

    //Show teams
    JsonInterface myParser;
    auto teams = myParser.LoadTeams("json/sampleteams.json");

    for (int i = 0; i < teams->size(); ++i ) {
        KW_Rect teamRect = {.x = 80, .y = 80 + 30*i, .w = 500, .h = 30};
        const char * teamname = (*teams)[i]->getName().c_str();
        KW_Widget * teamWidget = KW_CreateButtonAndLabel(gui, addNewMatchFrame, teamname, &teamRect);
        KW_SetWidgetUserData(teamWidget, (void *) teamname);
        KW_AddWidgetMouseDownHandler(teamWidget, firstTeamSelectedForMatch);
    }

}

void GFX_Iface::addMatchClicked(KW_Widget * widget, int b) {
    //Show new frame
    KW_Rect centerRect = {.x = 5, .y = 5, .w = 2038, .h = 1430};
    KW_Widget * addNewMatchFrame = KW_CreateFrame(gui, NULL, &centerRect);

    //Show teams
    JsonInterface myParser;
    auto teams = myParser.LoadTeams("json/sampleteams.json");

    for (int i = 0; i < teams->size(); ++i ) {
        KW_Rect teamRect = {.x = 80, .y = 80 + 30*i, .w = 500, .h = 30};
        const char * teamname = (*teams)[i]->getName().c_str();
        KW_Widget * teamWidget = KW_CreateButtonAndLabel(gui, addNewMatchFrame, teamname, &teamRect);
        KW_SetWidgetUserData(teamWidget, (void *) teamname);
        KW_AddWidgetMouseDownHandler(teamWidget, firstTeamSelectedForMatch);
    }

    //TODO First team selectable

    //TODO Show other teams with same category
    //TODO Second team selectable
    //TODO If selected (OK clicked) create
    //TODO Create match
    //TODO Close frame/widget
    //TODO Show match on leftFrame
    //TODO Move addNewMatch button

    SDL_Log("myLog: Add match button clicked, event handler is running.");
}

void GFX_Iface::RenderLoop() {
    //SDL_Log("myLog: Render loop is running");
    SDL_RenderClear(renderer);
    KW_ProcessEvents(gui);
    KW_Paint(gui);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000); //for checking if new frame is present
}

/*
 * just for testing
 * Create the title, label and editbox widgets
 * it was in Init()
 * */

/*JsonInterface jsonParser;
std::vector <Team*> * teams = jsonParser.LoadTeams("json/sampleteams.json");
if (teams->size() == 15) SDL_Log("Marha nagy 15");
for (int i = 0; i < teams->size(); ++i ) {
    SDL_Log("ciklus egy");
    KW_Rect teamRect = {.x = 80, .y = 80 + 30*i, .w = 500, .h = 30};
    const char * teamname = (*teams)[i]->getName().c_str();
    SDL_Log("Here comes teamname");
    SDL_Log("%s",teamname);
    KW_CreateLabel(gui, leftFrame, teamname , &teamRect);
    SDL_Log("** **");
}

KW_Rect titlerect = { .x = 0, .y = 10, .w = 300, .h = 30 };
KW_Rect labelrect = { .y = 100, .w = 60, .h = 30 };
KW_Rect editboxrect = { .y = 100, .w = 100, .h = 40 };
KW_Rect * rects[] = { &labelrect, &editboxrect };
unsigned weights[] = { 1, 4 };
KW_RectFillParentHorizontally(&leftFrameRect, rects, weights, 2, 10, KW_RECT_ALIGN_MIDDLE);
KW_CreateLabel(gui, leftFrame, "Editbox example", &titlerect);
KW_CreateLabel(gui, leftFrame, "Label", &labelrect);
KW_CreateEditbox(gui, leftFrame, "Edit me!", &editboxrect);*/