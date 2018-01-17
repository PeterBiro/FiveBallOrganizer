//
// Created by birop on 17/01/2018.
//

#include "Team.h"


Team::Team(std::string nm, std::string cat) {
    Team::Team(nm, cat, NULL);
}

Team::Team(std::string nm, std::string cat, std::string mail) {
    name = nm;
    category = cat;
    email = mail;
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
