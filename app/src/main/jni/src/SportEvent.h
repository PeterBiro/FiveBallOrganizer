//
// Created by birop on 22/03/2018.
//

#ifndef FIVEBALLORGANIZER_SPORTEVENT_H
#define FIVEBALLORGANIZER_SPORTEVENT_H

#include <string>
#include "GFX_Iface.h" // only for short time, it will propagate down to future controller



class SportEvent {
public:
    enum eventType {CHAMPIONSHIP, CUP};

    SportEvent(std::string sportsToInit[5], eventType eventTp );
    ~SportEvent()= default;

    void start();




private:
    std::string sports[5];
    eventType eventType = CHAMPIONSHIP;

};

#endif //FIVEBALLORGANIZER_SPORTEVENT_H
