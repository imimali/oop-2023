//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_CHAT_SESSION_H
#define CHAT_APP_CHAT_SESSION_H

#include "observer.h"
#include "user.h"
#include "message.h"

class ChatSession : public Subject {
private:
    std::vector<std::pair<User, Message>> messages;
public:
    void add_message(const User &u, const Message &m) {
        this->messages.emplace_back(u, m);
        this->notify();
    }

    auto get_messages() {
        return this->messages;
    }

};

#endif //CHAT_APP_CHAT_SESSION_H
