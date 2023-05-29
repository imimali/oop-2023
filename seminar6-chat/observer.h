//
// Created by Mali Imre Gergely on 15.05.2023.
//

#ifndef SEMINAR6_CHAT_OBSERVER_H
#define SEMINAR6_CHAT_OBSERVER_H

#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update() = 0;

    virtual ~Observer() = default;
};

class Subject {
    std::vector<Observer *> observers;
public:
    void register_observer(Observer *observer) {
        this->observers.push_back(observer);
    }

    void unregister_observer(Observer *observer) {
        this->observers.erase(
                std::find(this->observers.begin(),
                          this->observers.end(),
                          observer));
    }

    void notify() {
        for (auto &obs: this->observers) {
            obs->update();
        }
    }

    virtual ~Subject()=default;


};

#endif //SEMINAR6_CHAT_OBSERVER_H
