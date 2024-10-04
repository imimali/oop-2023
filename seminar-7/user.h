//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR_7_USER_H
#define SEMINAR_7_USER_H

#include <string>
class User{
    std::string userName;
    std::string displayName;
public:
    User(const std::string& userName, const std::string& displayName):displayName{displayName},userName{userName}{}
    std::string getUserName(){return this->userName;}
    std::string getDisplayName(){return this->displayName;}
    bool operator==(const User& other){return this->userName==other.userName;}
};

#endif //SEMINAR_7_USER_H
