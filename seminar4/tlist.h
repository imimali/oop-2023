//
// Created by Mali Imre Gergely on 10.04.2023.
//

#ifndef SEMINAR4_TLIST_H
#define SEMINAR4_TLIST_H

#include <vector>
#include <iostream>

#define INIT_CAP 2

template<typename T>
class DynamicVector {
private:
    int length{};
    int capacity{};
    T *elements;
    int id = -1;
    static int nr_instances;
public:
    DynamicVector();

    ~DynamicVector();

    DynamicVector(DynamicVector &other);

    DynamicVector<T> &operator=(const DynamicVector<T> &other);

    DynamicVector(DynamicVector<T> &&other) noexcept;

    DynamicVector<T> &operator=(DynamicVector<T> &&other) noexcept;

    void add(const T &t) {
        this->ensure_capacity();
        this->elements[this->length++] = t;
    }


    void ensure_capacity() {
        if (this->length < this->capacity) {
            return;
        }
        this->capacity *= 2;
        T *aux = new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            aux[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = aux;
    }
};

template<typename T>
DynamicVector<T> &DynamicVector<T>::operator=(DynamicVector<T> &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    delete[] this->elements;
    this->elements = other.elements;
    this->capacity = other.capacity;
    this->length = other.length;

    other.elements = nullptr;
    other.length = 0;
    other.capacity = 0;

    return *this;
}

template<typename T>
DynamicVector<T>::DynamicVector(DynamicVector<T> &&other) noexcept {
    this->elements = other.elements;
    this->length = other.length;
    this->capacity = other.capacity;

    other.elements = nullptr;
    other.length = 0;
    other.capacity = 0;
}

template<typename T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector<T> &other) {
    std::cout << "Copy assignment operator called on " << this->id << " and " << other.id << std::endl;
    if (this == &other) {
        return *this;
    }
    delete[] this->elements;
    this->length = other.length;
    this->capacity = other.capacity;
    this->elements = new T[other.capacity];
    for (int i = 0; i < this->length; i++) {
        this->elements[i] = other.elements[i];
    }
    return *this;
}

template<typename T>
DynamicVector<T>::DynamicVector(DynamicVector &other) {
    std::cout << "Copy constructor called on " << this->id << " and " << other.id << std::endl;
    this->length = other.length;
    this->capacity = other.capacity;
    this->elements = new T[other.capacity];
    for (int i = 0; i < this->length; i++) {
        this->elements[i] = other.elements[i];
    }

}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    std::cout << "Destructor called on " << this->id << std::endl;
    delete this->elements;

}

template<typename T>
DynamicVector<T>::DynamicVector() {
    std::cout << "Default constructor called for " << DynamicVector<T>::nr_instances << std::endl;
    this->id = DynamicVector<T>::nr_instances++;
    this->elements = new T[INIT_CAP];
    this->length = 0;
    this->capacity = INIT_CAP;
}

template<typename T>
int DynamicVector<T>::nr_instances = 0;

#endif //SEMINAR4_TLIST_H
