//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_USER_H
#define SEMINAR6_CHAT_USER_H

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

#endif //SEMINAR6_CHAT_USER_H
