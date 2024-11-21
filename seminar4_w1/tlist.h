//
// Created by Mali Imre Gergely on 10.04.2023.
//

#ifndef SEMINAR4_W1_TLIST_H
#define SEMINAR4_W1_TLIST_H
#define INIT_CAPACITY 10

#include <iostream>
#include <string>

template<typename T>
class d_vector {
private:
    T *elems;
    int length;
    int capacity;
    static int nr_instances;
    int id = -1;
public:
    d_vector();

    ~d_vector();

    d_vector(const d_vector<T> &v);

    d_vector<T> &operator=(const d_vector<T> &other);

    d_vector(d_vector<T> &&v);

    d_vector<T> &operator=(d_vector<T> &&other);

    void add(const T &t);

    T operator[](int index);

    T operator*();

    void operator()();

    std::string to_string() {
        return "List[length=" +
               std::to_string(this->length) +
               ", cap=" + std::to_string(this->capacity) +
               ", elems=" + std::to_string((long) this->elems) +
               "]";
    }
};

template<typename T>
void d_vector<T>::operator()() {
    std::cout<<"vector called as function"<<std::endl;
}

template<typename T>
T d_vector<T>::operator*() {
    return *this->elems;
}

template<typename T>
T d_vector<T>::operator[](int index) {
    return this->elems[index];
}

template<typename T>
void d_vector<T>::add(const T &t) {
    this->elems[this->length++] = t;
}

template<typename T>
d_vector<T> &d_vector<T>::operator=(d_vector<T> &&other) {
    std::cout << "move assignment called" << this->id << " " << other.id << std::endl;
    if (this == &other) { return *this; }
    this->length = other.length;
    this->capacity = other.capacity;
    delete[] this->elems;
    this->elems = other.elems;

    other.elems = nullptr;
    other.length = 0;
    other.capacity = 0;
    return *this;
}

template<typename T>
d_vector<T>::d_vector(d_vector<T> &&other) {
    std::cout << "move constructor called" << this->id << " " << other.id << std::endl;
    //std::cout << "move constructor called" << std::endl;
    this->length = other.length;
    this->capacity = other.capacity;
    this->elems = other.elems;

    other.elems = nullptr;
    other.length = 0;
    other.capacity = 0;
}

template<typename T>
d_vector<T> &d_vector<T>::operator=(const d_vector<T> &other) {
    std::cout << "copy assignment called" << std::endl;
    if (this == &other) {
        return *this;
    }
    this->length = other.length;
    this->capacity = other.capacity;
    delete[] this->elems;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->length; i++) {
        this->elems[i] = other.elems[i];
    }
    return *this;
}


template<typename T>
d_vector<T>::d_vector(const d_vector<T> &other) {
    std::cout << "copy constructor called" << this->id << " " << other.id << std::endl;
    this->length = other.length;
    this->capacity = other.capacity;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->length; i++) {
        this->elems[i] = other.elems[i];
    }
}

template<typename T>
d_vector<T>::~d_vector() {
    std::cout << "destructor called " << this->id << std::endl;
    delete[] this->elems;
}

template<typename F>
d_vector<F>::d_vector() {
    //std::cout << "constructor called " <<this->id<< std::endl;
    this->length = 0;
    this->id = d_vector<F>::nr_instances++;
    std::cout << "constructor called " << this->id << std::endl;
    this->capacity = INIT_CAPACITY;
    this->elems = new F[INIT_CAPACITY];
}

template<typename F>
int d_vector<F>::nr_instances = 0;


#endif //SEMINAR4_W1_TLIST_H
