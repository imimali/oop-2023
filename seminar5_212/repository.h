//
// Created by Mali Imre Gergely on 08.05.2023.
//

#ifndef SEMINAR5_212_REPOSITORY_H
#define SEMINAR5_212_REPOSITORY_H

#include <vector>
#include <algorithm>

using std::vector;

template<typename T>
class Repository {
    vector<T> elems;
public:
    Repository() = default;

    void add(const T &t) {
        this->elems.push_back(t);
    }

    T &find(const T &elem) {
        auto found = std::find(this->elems.begin(), this->elems.end(), elem);
        if (found == this->elems.end()) {
            throw std::runtime_error("Element not found");
        }
        return *found;
    }

    void update(const T &elem) {
        T& original = this->find(elem);
        original = elem;
    }


    vector<T> get_all() { return this->elems; }
};

#endif //SEMINAR5_212_REPOSITORY_H
