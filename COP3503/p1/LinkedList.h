#pragma once
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <vector>

using namespace std;
/*=======================Class Declerations==================*/
template <typename T> class LinkedList {
public:
  struct Node {
    T data;
    Node *next;
    Node *prev;
  };
  unsigned int _count;
  Node *_head;
  Node *_tail;
  /*====Behaviors====*/
  void PrintForward() const;
  void PrintReverse() const;
  void PrintForwardRecursive(const Node *node) const;
  void PrintReverseRecursive(const Node *node) const;
  /*====Accessors====*/
  unsigned int NodeCount() const;
  void FindAll(vector<Node *> &outData, const T &value) const;
  Node *Find(const T &data);
  const Node *Find(const T &data) const;
  const Node *GetNode(unsigned int index) const;
  Node *GetNode(unsigned int index);
  Node *Head();
  Node *Tail();
  const Node *Head() const;
  const Node *Tail() const;
  /*====Insertion====*/
  void AddHead(const T &data);
  void AddTail(const T &data);
  void AddNodesHead(const T *data, unsigned int count);
  void AddNodesTail(const T *data, unsigned int count);
  void InsertAfter(Node *node, const T &data);
  void InsertBefore(Node *node, const T &data);
  void InsertAt(const T &data, unsigned int index);
  /*====Removal====*/
  bool RemoveHead();
  bool RemoveTail();
  unsigned int Remove(const T &data);
  bool RemoveAt(unsigned int index);
  void Clear();
  /*====Operations====*/
  const T &operator[](unsigned int index) const;
  T &operator[](unsigned int index);
  bool operator==(const LinkedList<T> &rhs) const;
  LinkedList<T> &operator=(const LinkedList<T> &rhs);
  /*====Construction/Destruction====*/
  LinkedList();
  LinkedList(const LinkedList<T> &list);
  ~LinkedList();
};
/*=====================Class Definitions=============================*/

/*====Default Constructor====*/
template <typename T> LinkedList<T>::LinkedList() {
  _count = 0;
  _head = nullptr;
  _tail = nullptr;
}
/*====Copy Constructor====*/
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T> &list) {
  _count = 0;
  _head = nullptr;
  _tail = nullptr;
  Node *current = list._head;
  while (current != nullptr) {
    AddTail(current->data);
    current = current->next;
  }
}
/*====Copy Assignement Operator====*/
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
  if (this != &rhs) {
    Clear();
    Node *current = rhs._head;
    while (current != nullptr) {
      AddTail(current->data);
      current = current->next;
    }
  }
  return *this;
}
/*====Destructor====*/
template <typename T> LinkedList<T>::~LinkedList() { Clear(); }
/*====Insertions====*/
template <typename T> void LinkedList<T>::AddHead(const T &data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  if (_head == nullptr) {
    _head = newNode;
    _tail = newNode;
  } else {
    newNode->next = _head;
    _head->prev = newNode;
    _head = newNode;
  }
  _count++;
}
template <typename T> void LinkedList<T>::AddTail(const T &data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = nullptr;
  newNode->prev = nullptr;
  if (_head == nullptr) {
    _head = newNode;
    _tail = newNode;
  } else {
    newNode->prev = _tail;
    _tail->next = newNode;
    _tail = newNode;
  }
  _count++;
}
template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count) {
  for (unsigned int i = count; i > 0; i--) {
    AddHead(data[i - 1]);
  }
}
template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count) {
  for (unsigned int i = 0; i < count; i++) {
    AddTail(data[i]);
  }
}
template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data) {
  if (node == _tail) {
    AddTail(data);
  } else {
    Node *newNode = new Node;
    Node *after = node->next;
    node->next = newNode;
    newNode->prev = node;
    after->prev = newNode;
    newNode->next = after;
    newNode->data = data;
    _count++;
  }
}
template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data) {
  if (node == _head) {
    AddHead(data);
  } else {
    Node *newNode = new Node;
    Node *before = node->prev;
    newNode->next = node;
    newNode->prev = before;
    node->prev = newNode;
    before->next = newNode;
    newNode->data = data;
    _count++;
  }
}
template <typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index) {
  if (index > _count)
    throw out_of_range("Index is out of range");
  if (index == 0)
    AddHead(data);
  else if (index == _count)
    AddTail(data);
  else {
    Node *node = GetNode(index);
    InsertBefore(node, data);
  }
}
/*====Removal====*/
template <typename T> bool LinkedList<T>::RemoveHead() {
  if (_head == nullptr)
    return false;
  Node *temp = _head;
  if (_head == _tail) {
    _head = nullptr;
    _tail = nullptr;
  } else {
    _head = _head->next;
    _head->prev = nullptr;
  }
  delete temp;
  _count--;
  return true;
}
template <typename T> bool LinkedList<T>::RemoveTail() {
  if (_head == nullptr)
    return false;
  Node *temp = _tail;
  if (_head == _tail) {
    _head = nullptr;
    _tail = nullptr;
  } else {
    _tail = _tail->prev;
    _tail->next = nullptr;
  }
  delete temp;
  _count--;
  return true;
}
template <typename T> unsigned int LinkedList<T>::Remove(const T &data) {
  unsigned int removed = 0;
  Node *current = _head;
  while (current != nullptr) {
    Node *next = current->next;
    if (current->data == data) {
      if (current == _head)
        RemoveHead();
      else if (current == _tail)
        RemoveTail();
      else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        _count--;
      }
      removed++;
    }
    current = next;
  }
  return removed;
}
template <typename T> bool LinkedList<T>::RemoveAt(unsigned int index) {
  if (index >= _count)
    return false;
  Node *trash = GetNode(index);
  if ((trash == _head))
    RemoveHead();
  else if (trash == _tail)
    RemoveTail();
  else {
    trash->prev->next = trash->next;
    trash->next->prev = trash->prev;
    delete trash;
    _count--;
  }
  return true;
}
template <typename T> void LinkedList<T>::Clear() {
  Node *current = _head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
    _count--;
  }
  _head = nullptr;
  _tail = nullptr;
  _count = 0;
}
/*====Accessors====*/
template <typename T> unsigned int LinkedList<T>::NodeCount() const {
  return _count;
}
template <typename T> typename LinkedList<T>::Node *LinkedList<T>::Head() {
  return _head;
}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Head() const {
  return _head;
}
template <typename T> typename LinkedList<T>::Node *LinkedList<T>::Tail() {
  return _tail;
}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Tail() const {
  return _tail;
}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) {
  if (index >= _count) {
    throw out_of_range("Index is out of range");
  } else {
    Node *current = _head;
    for (unsigned int i = 0; i < index; i++) {
      current = current->next;
    }
    return current;
  }
}
template <typename T>
const typename LinkedList<T>::Node *
LinkedList<T>::GetNode(unsigned int index) const {
  if (index >= _count) {
    throw out_of_range("Index is out of range");
  } else {
    Node *current = _head;
    for (unsigned int i = 0; i < index; i++) {
      current = current->next;
    }
    return current;
  }
}
template <typename T>
void LinkedList<T>::FindAll(vector<Node *> &outData, const T &value) const {
  Node *current = _head;
  while (current != nullptr) {
    if (current->data == value)
      outData.push_back(current);
    current = current->next;
  }
}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data) {
  Node *current = _head;
  while (current != nullptr) {
    if (current->data == data)
      return current;
    current = current->next;
  }
  return nullptr;
}
template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data) const {
  Node *current = _head;
  while (current != nullptr) {
    if (current->data == data)
      return current;
    current = current->next;
  }
  return nullptr;
}
/*====Operators====*/
template <typename T> T &LinkedList<T>::operator[](unsigned int index) {
  return GetNode(index)->data;
}
template <typename T>
const T &LinkedList<T>::operator[](unsigned int index) const {
  return GetNode(index)->data;
}
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const {
  if (this->_count != rhs._count)
    return false;
  const Node *leftCurrent = this->_head;
  const Node *rightCurrent = rhs._head;
  while (rightCurrent != nullptr) {
    if (leftCurrent->data != rightCurrent->data)
      return false;
    leftCurrent = leftCurrent->next;
    rightCurrent = rightCurrent->next;
  }
  return true;
}
/*====Behaviors=====*/
template <typename T> void LinkedList<T>::PrintForward() const {
  Node *current = _head;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->next;
  }
}
template <typename T> void LinkedList<T>::PrintReverse() const {
  Node *current = _tail;
  while (current != nullptr) {
    cout << current->data << endl;
    current = current->prev;
  }
}
template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node *node) const {
  cout << node->data << endl;
  if (node->next != nullptr)
    PrintForwardRecursive(node->next);
}
template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node *node) const {
  cout << node->data << endl;
  if (node->prev != nullptr)
    PrintReverseRecursive(node->prev);
}