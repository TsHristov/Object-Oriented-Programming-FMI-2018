#include "DynamicArray.h"

DynamicArray :: DynamicArray() {
  size     = 0;
  capacity = 4;
  array    = new int[capacity]; 
}

DynamicArray :: ~DynamicArray() {
  Free();
}

DynamicArray :: DynamicArray(const DynamicArray& other) {
  CopyFrom(other);
}

DynamicArray& DynamicArray :: operator=(const DynamicArray& other) {
  if (this == &other) {
    return *this; 
  } else {
    Free();
    CopyFrom(other);
    return *this;
  }
}

void DynamicArray :: Append(int value) {
  if (size == capacity) Resize();
  array[size++] = value;
}

void DynamicArray :: Insert(size_t index, int value) {
  if (index < 0 || index >= capacity) throw std::out_of_range("Index Out Of Range!");
  size_t i;
  for (i = GetSize(); i > index; i--) {
    array[i] = array[i-1];
  }
  ++size;
  if (size == capacity) Resize();
  array[i] = value;
}

int DynamicArray :: Index(int value) const {
  for (size_t i = 0; i < size; ++i) {
    if (array[i] == value) return i;
  }
  return -1;
}

int DynamicArray :: Count(int value) const {
  int count = 0;
  for (size_t i = 0; i < size; ++i) {
    if (array[i] == value) ++count;
  }
  return count;
}

void DynamicArray :: Print() const {
  std::cout << "Capacity:" << capacity << "\n";
  std::cout << "Size:"     << size     << "\n";
  std::cout << "[";
  for(size_t i = 0; i < size; ++i) {
    std::cout << array[i] << ", ";
  }
  std::cout << "]\n";
}

int& DynamicArray :: operator[](size_t index) const {
  if (index < 0 || index >= capacity) {
    throw std::out_of_range("Index Out Of Range!");
  } else {
    return array[index];
  }
}

bool DynamicArray :: operator==(const DynamicArray& other) const {
  if (this == &other) return true;
  int this_length  = size;
  int other_length = other.GetSize();
  if (this_length != other_length) return false;
  for(size_t i=0; i < size; i++) {
    if (array[i] != other.array[i]) return false;
  }
  return true;
}

bool DynamicArray :: operator!=(const DynamicArray& other) const {
  return !(*this == other);
}

void DynamicArray :: Resize() {
  size_t new_capacity = capacity * 2;
  int *resized = new int[new_capacity];
  for (size_t i = 0; i < size; ++i) {
    resized[i] = array[i];
  }
  delete[] array;
  capacity = new_capacity;
  array    = resized;
}

void DynamicArray :: Free() {
  if (array) delete[] array;
  size     = 0;
  capacity = 0; 
}

void DynamicArray :: CopyFrom(const DynamicArray& other) {
  array = new int[other.capacity];
  for(size_t i = 0; i <= other.capacity; ++i) {
    array[i] = other.array[i];
  }
  size     = other.size;
  capacity = other.capacity;
}
