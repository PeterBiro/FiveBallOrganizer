//
// Created by birop on 17/01/2018.
//
#include "Team.h"
#include "SDL.h"

Team::Team(std::string nm, std::string cat) : Team(nm, cat, ""){}

Team::Team(std::string nm, std::string cat, std::string mail) {
    SDL_Log("second constructor is called\n");
    name = nm;
    category = cat;
    email = mail;
    SDL_Log("Team created with name: %s , category: %s, e-mail: %s\n", name.c_str(), category.c_str(), email.c_str());
}

std::string Team::getName() {
    return name;
}

void Team::setName(std::string newName) {
    name = newName;
}

std::string Team::getCategory() {
    return category;
}

void Team::setCategory(std::string newCategory) {
    category = newCategory;
}

std::string Team::getEmail() {
    return email;
}

void Team::setEmail(std::string newEmail) {
    email = newEmail;
}
