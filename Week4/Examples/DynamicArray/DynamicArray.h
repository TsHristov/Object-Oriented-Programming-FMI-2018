#pragma once
#include <iostream>

class DynamicArray
{
 private:
  size_t size;
  size_t capacity;
  int *array;

 public:
  DynamicArray();
  ~DynamicArray();
  DynamicArray(const DynamicArray&);
  DynamicArray& operator=(const DynamicArray&);

 public:
  void Append(int value);
  void Insert(size_t index, int value);
  int Index(int value)  const;
  int Count(int value)  const;
  void Print()          const;
  bool Empty()          const { return size == 0; }
  size_t GetSize()      const { return size; }
  size_t GetCapacity()  const { return capacity; }
  
 public:
  int& operator[](size_t index)        const;
  bool operator==(const DynamicArray&) const;
  bool operator!=(const DynamicArray&) const;
  
 private:
  void Resize();
  void Free();
  void CopyFrom(const DynamicArray&);
};
