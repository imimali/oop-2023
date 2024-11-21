//
// Created by Mali Imre Gergely on 29.05.2023.
//

#ifndef SEMINAR_7_MESSAGE_H
#define SEMINAR_7_MESSAGE_H

class Message {
    tm timestamp;
    std::string message;
public:
    Message(const std::string &message) : message{message} {
        time_t now = time(nullptr);
        auto ltm = localtime(&now);
        this->timestamp = *ltm;
    }
    std::string getMessage()const{return this->message;}
    tm getTimestamp()const{return this->timestamp;}

    std::string getTimeStampAsString()const{
        std::stringstream t;
        t << "[" << this->timestamp.tm_mday << "." << this->timestamp.tm_mon + 1 << "." << this->timestamp.tm_year + 1900;
        t << "; " << this->timestamp.tm_hour << ":" << this->timestamp.tm_min << "]";
        return t.str();
    }
};
#endif //SEMINAR_7_MESSAGE_H
