//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR7_2_MESSAGE_H
#define SEMINAR7_2_MESSAGE_H
#include <string>
#include "user.h"
class Message {
    std::string text;
    const User &user;
public:
    Message(const User &u, const std::string &t) : text{t}, user{u} {

    }

    const User &get_user() {
        return this->user;
    }

    std::string get_text() const{
        return text;
    }
};
#endif //SEMINAR7_2_MESSAGE_H
