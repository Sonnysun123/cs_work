#include "DynamicArray.h"
#include <iostream>
using namespace std;
DynamicArray::DynamicArray(int initialCapacity) {
  _size = 0;
  _capacity = initialCapacity;
  _data = new int[_capacity];
}
DynamicArray::~DynamicArray() { delete[] _data; }
DynamicArray::DynamicArray(const DynamicArray &otherObject) {
  this->_size = otherObject._size;
  this->_capacity = otherObject._capacity;
  this->_data = new int[_capacity];
  for (int i = 0; i < _size; i++) {
    _data[i] = otherObject._data[i];
  }
}
DynamicArray &DynamicArray::operator=(const DynamicArray &rhs) {
  delete[] _data;
  this->_size = rhs._size;
  this->_capacity = rhs._capacity;
  this->_data = new int[_capacity];
  for (int i = 0; i < _size; i++) {
    _data[i] = rhs._data[i];
  }
  return *this;
}
const int *DynamicArray::GetData() const { return _data; }
int DynamicArray::GetCapacity() const { return _capacity; }
int DynamicArray::GetSize() const { return _size; }

void DynamicArray::Add(int newItem) {
  if (_size == _capacity) {
    int *newArray = new int[_capacity + 1];
    for (int i = 0; i < _size; i++) {
      newArray[i] = _data[i];
    }
    delete[] _data;
    _data = newArray;
  }
  _data[_size] = newItem;
  _size++;
}
void DynamicArray::Remove() {
  if (_size == 0)
    cout << "Array is empty, cannot remove item." << endl;
  else {
    _size--;
    int *newArray = new int[_capacity];
    for (int i = 0; i < _size; i++) {
      newArray[i] = _data[i];
    }
    delete[] _data;
    _data = newArray;
  }
}
void DynamicArray::Clear() {
  _size = 0;
  _capacity = 1;
  delete[] _data;
  _data = new int[_capacity];
}
void DynamicArray::Print() const {
  for (int i = 0; i < _size; i++) {
    cout << _data[i] << endl;
  }
}