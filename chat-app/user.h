//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_USER_H
#define CHAT_APP_USER_H

#include <string>

class User {
    std::string username;
    int id;
public:
    User(int id, const std::string &username) : username{username}, id{id} {}

    std::string get_username()const { return this->username; }

    int get_id()const { return this->id; }

    bool operator=(const User &other){
        return (this->id == other.id && this->username == other.username);
    }
};

#endif //CHAT_APP_USER_H
