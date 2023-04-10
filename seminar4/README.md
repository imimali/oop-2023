# Seminar 4

## On templates
We usually use them for types, but we can do that even for values
```c++
template<int N>
int f() {
    return N + 10;
}
```
And then call it like `f<10>()`.

Let's build our dynamic vector with templates!

```c++
template<typename T>
class DynamicVector {
private:
    int length;
    int capacity;
    T *elements;
    //...
}

template<typename T>
DynamicVector<T>::DynamicVector() {
    this->elements = new T[INIT_CAP];
    this->length = 0;
    this->capacity = INIT_CAP;
}
//...
```
Don't forget to put everything in the header!

## Rule of three
Since we're managing resources(the constructor dynamically allocates),
we'll have to take care of some special functions:

- Destructor(obviously):
```c++
template<typename T>
DynamicVector<T>::~DynamicVector() {
    delete this->elements;

}
```

- Copy constructor:
```c++
template<typename T>
DynamicVector<T>::DynamicVector(DynamicVector &other) {
    this->length = other.length;
    this->capacity = other.capacity;
    this->elements = new T[other.capacity];
    for (int i = 0; i < this->length; i++) {
        this->elements[i] = other.elements[i];
    }

}
```

- Copy assignment operator:
```c++
template<typename T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector<T> &other) {
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
```
:lightbulb: watch out for self-assignment

That so far sums up the rule of three. But there's more. We have the rule of [five](https://youtu.be/sXYIxJScSik?t=106).

This is for move semantics.

- Move constructor
```c++
template<typename T>
DynamicVector<T>::DynamicVector(DynamicVector<T> &&other) noexcept {
    this->elements = other.elements;
    this->length = other.length;
    this->capacity = other.capacity;

    other.elements = nullptr;
    other.length = 0;
    other.capacity = 0;
}
```
:lightbulb: Note how this one doesn't deallocate the elements nor does it copy them over. That would defeat the purpose.

:lightbulb: `&&` means `rvalue`, not double reference

- Move assignment operator:

```c++
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
```





