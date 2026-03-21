#pragma once

class DynamicArray {
    int* _data;
    int _size;
    int _capacity;
public:
   
//Constructors and Destructor
    DynamicArray(int initialCapacity = 1);
    ~DynamicArray();
    //Copy constructor
    DynamicArray(const DynamicArray& otherObject);
    //copy assignment
    DynamicArray& operator=(const DynamicArray& rhs);
    //Accessors
    const int* GetData() const;
    int GetCapacity() const;
    int GetSize() const;
    //Mutators
    void Add(int newItem);
    void Clear();
    void Remove();
    //Behaviors
    void Print() const;
};