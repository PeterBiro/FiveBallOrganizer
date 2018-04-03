//
// Created by birop on 22/03/2018.
//

#include "MainFrame.h"



void MainFrame::start() {
    std::string sports[5] = {"foci", "kosár", "röplabda", "tollas", "ping-pong"};
    SportEvent sportEvent(sports, SportEvent::eventType::CHAMPIONSHIP);
    sportEvent.start();
}
