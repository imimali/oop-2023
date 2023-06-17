//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR7_2_USER_H
#define SEMINAR7_2_USER_H


#include <string>

class User {
    std::string username;
    int id;
public:
    User(const std::string &uname, int id) : username{uname}, id{id} {

    }

    std::string get_username() const{ return this->username; }

    int get_id() { return this->id; }
};

#endif //SEMINAR7_2_USER_H
