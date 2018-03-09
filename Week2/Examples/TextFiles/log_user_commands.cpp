#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cout << "Usage: " << argv[0] << " <log_file> \n";
    return 1;
  }

  const char* log_file_name = argv[1];
  ofstream log_file(log_file_name, ios::ate | ios::app);
  
  char command[100];
  do {
    cin.getline(command, 100);
    time_t t = time(0);
    struct tm * now = localtime(&t);
    log_file << "Logged at: "
	     << (now->tm_year + 1900) << '-'
	     << (now->tm_mon + 1) << '-'
	     << (now->tm_mday) << " "
	     << (now->tm_hour) << ":"
	     << (now->tm_min)  << ":"
	     << (now->tm_sec)  << "\n";
    log_file << "Command: ";
    log_file << command << "\n";
    log_file << "----------------------------------------------\n";
  } while(strcmp(command, "QUIT"));

  log_file.close();
  
  return 0;
}
