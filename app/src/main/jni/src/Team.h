//
// Created by birop on 17/01/2018.
//

#ifndef FIVEBALLORGANIZER_TEAM_H
#define FIVEBALLORGANIZER_TEAM_H

#include <string>

class Team {
public:

    Team(std::string name, std::string category);
    Team(std::string name, std::string category, std::string email);

    ~Team()=default;

    std::string getName();
    void setName(std::string newName);
    std::string getCategory();
    void  setCategory(std::string newCategory);
    std::string getEmail();
    void setEmail(std::string newEmail);


private:
    std::string name;
    std::string category;
    std::string email;
};


#endif //FIVEBALLORGANIZER_TEAM_H
