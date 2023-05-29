//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_MESSAGE_H
#define SEMINAR6_CHAT_MESSAGE_H

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

    std::string get_text() {
        return text;
    }
};

#endif //SEMINAR6_CHAT_MESSAGE_H
