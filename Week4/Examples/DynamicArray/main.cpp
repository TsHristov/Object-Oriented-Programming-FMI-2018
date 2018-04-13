#include <iostream>
#include "DynamicArray.h"

void Test_CreateDynamicArray()
{
  std::cout << "can create empty array...";
  DynamicArray array;
  std::cout << "OK\n";
}

void Test_AppendToArray()
{
  std::cout << "can append value to end of array...";
  DynamicArray array;
  array.Append(10);
  std::cout << (array[array.GetSize() - 1] == 10 ? "OK\n" : "NOK\n");
}

void Test_GetIndexOfElement()
{
  std::cout << "can retrieve the index of an element...";
  DynamicArray array;
  array.Append(10);
  bool condition1 = array.Index(10) == 0;
  bool condition2 = array.Index(-666) == -1;
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
}

void Test_CountElements(){
  std::cout << "can count the elements with particular value...";
  DynamicArray array;
  array.Append(1);
  array.Append(1);
  array.Append(1);
  array.Append(2);
  bool condition = array.Count(1) == 3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Insert()
{
  std::cout << "can insert an element at given index...";
  DynamicArray array;
  for(int i = 0; i < 5; i++) {
    array.Append(i);
  }
  array.Insert(1,666);
  bool condition = array.Index(666) == 1;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Empty()
{
  std::cout << "can check if array is empty...";
  DynamicArray array;
  bool condition1 = array.Empty();
  array.Append(0);
  bool condition2 = !array.Empty();
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
}

void Test_OperatorSquareBrackets()
{
  std::cout << "can retrieve an element using []...";
  DynamicArray array;
  array.Append(1);
  array.Append(2);
  bool condition1 = array[0] == 1;
  array[0] = 5;
  bool condition2 = array[0] == 5;
  bool condition3  = false;
  try {
    int value = array[-99999];
  } catch (std::out_of_range& e) {
    condition3 = true;
  }
  std::cout << (condition1 && condition2 && condition3 ? "OK\n" : "NOK\n");
}

void Test_Compare()
{
  std::cout << "can compare two array instances with ==...";
  DynamicArray array1;
  array1.Append(1);
  array1.Append(2);
  DynamicArray array2;
  array2.Append(1);
  array2.Append(2);
  bool condition = array1 == array2;
  std::cout << (condition ? "OK\n" : "NOK\n");
  std::cout << "can compare two instances with !=...";
  array1[0] = 5;
  condition = array1 != array2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class DynamicArray: \n";
  Test_CreateDynamicArray();
  Test_AppendToArray();
  Test_GetIndexOfElement();
  Test_CountElements();
  Test_Insert();
  Test_Empty();
  Test_OperatorSquareBrackets();
  Test_Compare();
  return 0;
}
