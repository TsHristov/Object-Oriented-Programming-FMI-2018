#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
  // Отваряме текущия .cpp файл, чрез класа за четене от файлове ifstream (input file stream).
  ifstream source_file("print_myself.cpp", ios::ate); // флаг по подразбиране: ios::in

  streampos file_size;

  if(source_file.is_open()) {
    file_size = source_file.tellg();
  }

  // Връщаме позицията за четене в началото на файла:
  source_file.seekg(0);
  
  char character;
  // Проверка дали файла е бил успешно отворен:
  if(source_file.is_open()) {
    // Четем символ по символ от файла:
    while(source_file.get(character) && !source_file.eof()) {
      // Пишем резултата на стандартния изход:
	cout << character;
    }
    source_file.close();
  }
  
  cout << "Bytes read/written:" << file_size << "\n";

  return 0;
}
