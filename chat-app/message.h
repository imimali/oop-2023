//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_MESSAGE_H
#define CHAT_APP_MESSAGE_H

#include <ctime>
#include <string>
#include <sstream>

class Message {
    tm timestamp;
    std::string message;
public:
    Message(const std::string &message) : message{message} {
        time_t now = time(nullptr);
        auto local_time = localtime(&now);
        this->timestamp = *local_time;
    }

    std::string get_message() const { return this->message; }

    tm get_timestamp() const { return this->timestamp; }

    std::string get_timestamp_string() {
        std::stringstream ss;
        ss << "[" << this->timestamp.tm_mday << "." << this->timestamp.tm_mon + 1 << "."
           << this->timestamp.tm_year + 1900;
        ss << "; " << this->timestamp.tm_hour << ":" << this->timestamp.tm_min << "]";

        return ss.str();
    }
};

#endif //CHAT_APP_MESSAGE_H
