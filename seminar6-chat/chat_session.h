//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_CHAT_SESSION_H
#define SEMINAR6_CHAT_CHAT_SESSION_H

#include <vector>
#include "message.h"
#include "observer.h"


class ChatSession : public Subject {
    std::vector<Message> messages;
public:
    void add_message(const User &user, const std::string &message) {
        this->messages.emplace_back(user, message);
        this->notify();
    }

    auto get_messages(){return this->messages;}
};

#endif //SEMINAR6_CHAT_CHAT_SESSION_H
