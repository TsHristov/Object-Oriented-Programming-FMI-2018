#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 3) {
    cout << "Usage: " << argv[0] << " <source> " << " <destination> \n";
    return 1;
  }
  const char* source_file_name      = argv[1];
  const char* destination_file_name = argv[2];

  ifstream source(source_file_name);
  ofstream destination(destination_file_name, ios::trunc);

  char character;
  if(source.is_open() && destination.is_open()) {
    while(source.get(character) && !source.eof()) {
      destination << character;
    }
  }

  source.close();
  destination.close();
  
  return 0;
}
