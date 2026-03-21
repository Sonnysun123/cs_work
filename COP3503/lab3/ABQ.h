#pragma once
#include <iostream>

template <typename T> class ABQ {
  int _size;
  int _capacity;
  int _scaleFactor = 2;
  T *_data;

public:
  /*============CONSTRUCTORS====================*/
  ABQ();                             // default constructor
  ABQ(int initialCapacity);          // parameterized constructor
  ABQ(const ABQ<T> &other);          // copy constructor
  ABQ &operator=(const ABQ<T> &rhs); // copy assignment operator
  ~ABQ();                            // destructor

  /*============Mutators=====================*/
  void enqueue(T newItem); // add item to top of ABQ
  T dequeue();             // remove and return item from top of ABQ

  /*===========ACCESSORS==================*/
  T peek();               // return item from top of ABQ without removing it
  unsigned int getSize(); // return current size of ABQ
  unsigned int getMaxCapacity(); // return the current max capacity of the ABQ
  T *getData();                  // Return the array representing the ABQ
};

/*=================CLASS DEFINITIONS======================*/

template <typename T> // default constructor
ABQ<T>::ABQ() {
  _size = 0;
  _capacity = 1;
  _data = new T[_capacity];
}

template <typename T> // paramaterized constructor
ABQ<T>::ABQ(int initialCapacity) {
  _size = 0;
  _capacity = initialCapacity;
  _data = new T[_capacity];
}

template <typename T> // copy constructor
ABQ<T>::ABQ(const ABQ<T> &other) {
  _size = other._size;
  _capacity = other._capacity;
  _data = new T[_capacity];
  for (int i = 0; i < _size; i++) {
    _data[i] = other._data[i];
  }
}

template <typename T> // copy assignment operator
ABQ<T> &ABQ<T>::operator=(const ABQ<T> &rhs) {
  _size = rhs._size;
  _capacity = rhs._capacity;
  _data = new T[_capacity];
  for (int i = 0; i < _capacity; i++) {
    _data[i] = rhs._data[i];
  }
  return *this;
}

template <typename T> // destructor
ABQ<T>::~ABQ() {
  delete[] _data;
}

template <typename T> void ABQ<T>::enqueue(T newItem) {
  // if ABQ is full, create new array and copy old items
  // delete old array and point to new array
  if (_size == _capacity) {
    T *newABQ = new T[_capacity * _scaleFactor];
    for (int i = 0; i < _size; i++) {
      newABQ[i] = _data[i];
    }
    delete[] _data;
    _data = newABQ;
    _capacity *= _scaleFactor;
  }
  _data[_size] = newItem;
  _size++;
}

template <typename T> T ABQ<T>::dequeue() {
  // throws runtime error if ABQ is empty
  // re-adjust the size of the ABQ if necessary
  // Removes the top item and returns it
  if (_size == 0) {
    throw std::runtime_error("An error has occured");
  }
  _size--;
  double percentFull = (double)_size / _capacity;
  T firstItem = _data[0];
  T *newABQ;
  if (percentFull < 1 / (double)_scaleFactor) {
    newABQ = new T[_capacity / _scaleFactor];
    for (int i = 0; i < _size; i++) {
      newABQ[i] = _data[i + 1];
    }
    _capacity /= _scaleFactor;
  } else {
    newABQ = new T[_capacity];
    for (int i = 0; i < _size; i++) {
      newABQ[i] = _data[i + 1];
    }
  }
  delete[] _data;
  _data = newABQ;
  return firstItem;
}

template <typename T> T ABQ<T>::peek() {
  if (_size == 0) {
    throw std::runtime_error("An error has occured");
  }
  return _data[0];
}
template <typename T> unsigned int ABQ<T>::getSize() { return _size; }

template <typename T> unsigned int ABQ<T>::getMaxCapacity() {
  return _capacity;
}

template <typename T> T *ABQ<T>::getData() { return _data; }