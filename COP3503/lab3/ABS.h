#pragma once
#include <iostream>

template <typename T>
class ABS {
    int _size;
    int _capacity;
    int _scaleFactor = 2;
    T* _data;
    
public:
    /*============CONSTRUCTORS====================*/
    ABS(); // default constructor
    ABS(int initialCapacity); // parameterized constructor
    ABS(const ABS<T>& other); // copy constructor
    ABS& operator=(const ABS<T>& rhs); // copy assignment operator
    ~ABS(); // destructor
    
    /*============Mutators=====================*/
    void push(T newItem); // add item to top of ABS
    T pop(); // remove and return item from top of ABS

    /*===========ACCESSORS==================*/
    T peek(); // return item from top of ABS without removing it
    unsigned int getSize(); // return current size of ABS
    unsigned int getMaxCapacity(); // return the current max capacity of the ABS
    T* getData(); //Return the array representing the ABS
};

/*=================CLASS DEFINITIONS======================*/

template <typename T> // default constructor
ABS<T>::ABS() {
    _size = 0;
    _capacity = 1;
    _data = new T[_capacity];
}

template <typename T> // paramaterized constructor
ABS<T>::ABS(int initialCapacity) {
    _size = 0;
    _capacity = initialCapacity;
    _data = new T[_capacity];
}

template <typename T> // copy constructor
ABS<T>::ABS(const ABS<T>& other) {
    _size = other._size;
    _capacity = other._capacity;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }   
}

template <typename T> // copy assignment operator
ABS<T>& ABS<T>::operator=(const ABS<T>& rhs) {
    _size = rhs._size;
    _capacity = rhs._capacity;
    _data = new T[_capacity];
    for (int i = 0; i <_capacity; i++) {
        _data[i] = rhs._data[i];
    }
    return *this;
}

template <typename T> // destructor
ABS<T>::~ABS() { delete[] _data; }

template <typename T>
void ABS<T>::push(T newItem) {
    // if ABS is full, create new array and copy old items
    // delete old array and point to new array
    if (_size == _capacity) {
        T* newABS = new T[_capacity * _scaleFactor];
        for (int i = 0; i < _size; i++) {
            newABS[i] = _data[i];
        }
        delete[] _data;
        _data = newABS;
        _capacity *= _scaleFactor;
    }
    _data[_size] = newItem;
    _size++;
}

template <typename T>
T ABS<T>::pop() {
    // throws runtime error if ABS is empty
    // re-adjust the size of the ABS if necessary
    // Removes the top item and returns it
    if (_size == 0) {
        throw std::runtime_error("An error has occured");
    }
    _size--;
    double percentFull = (double)_size / _capacity;
    T lastItem = _data[_size];
    T* newABS;
    if (percentFull < 1 / (double)_scaleFactor) {
        newABS = new T[_capacity / _scaleFactor];
        for (int i = 0; i < _size; i++) {
            newABS[i] = _data[i];
        }
        _capacity /= _scaleFactor;
    }
    else {
        newABS = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newABS[i] = _data[i];
        }
    }
    delete[] _data;
    _data = newABS;
    return lastItem;
}

template <typename T>
T ABS<T>::peek() {
    if (_size == 0) {
        throw std::runtime_error("An error has occured");
    }
    return _data[_size - 1];
}
template <typename T>
unsigned int ABS<T>::getSize() { return _size; }

template <typename T>
unsigned int ABS<T>::getMaxCapacity() { return _capacity; }

template <typename T>
T* ABS<T>::getData() { return _data; }