//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef CHAT_APP_OBSERVER_H
#define CHAT_APP_OBSERVER_H

#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() = default;
};

class Subject {
private:
    std::vector<Observer *> observers;
public:
    virtual ~Subject() = default;

    void register_observer(Observer *obs) {
        this->observers.push_back(obs);
    }

    void unregister_observer(Observer *obs) {
        this->observers.erase(std::find(this->observers.begin(), this->observers.end(), obs));
    }

    void notify() {
        for (auto &obs: this->observers) {
            obs->update();
        }
    }
};

#endif //CHAT_APP_OBSERVER_H
