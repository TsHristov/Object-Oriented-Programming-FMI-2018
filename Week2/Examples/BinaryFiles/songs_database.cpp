#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

enum RETURN_CODES {
  SUCCESS,
  ERROR_OPENING_FILE,
  ERROR_WRITING_FILE,
  ERROR_READING_FILE,
};

struct Song {
  char name[50];
  unsigned length;
};

// Описание:
//     Записва един обект тип Song във файл с име `file_name`.
int WriteSongToFile(Song& song, const char* file_name) {
  ofstream file(file_name, ios::binary | ios::app);

  if(file.is_open()) {
    // Записваме обекта song във двоичния файл:
    file.write((const char*)&song, sizeof(Song));

    // Проверяваме дали писането е било успешно:
    if(file.bad()) {
      cerr << "Writing to " << file_name << " failed\n";
      return ERROR_WRITING_FILE;
    }

    file.close();
    return SUCCESS;
  }

  return ERROR_WRITING_FILE;
}

// Описание:
//     Прочита n-тата песен записана във файла:
int ReadSongFromFile(Song& song, const char* file_name, int n) {
  ifstream file(file_name, ios::binary);
  
  if(file.is_open()) {
    // Позиционираме маркера за четене от файла, като
    // прескачаме n-1 Song структури спрямо началото на файла:
    file.seekg((n-1)*sizeof(Song), ios::beg);
    file.read((char*)&song, sizeof(Song));

    // Проверяваме дали успешно сме прочели песен от файла:
    if(file.bad()){
      cerr << "Reading from " << file_name << " failed\n";
      return ERROR_READING_FILE;
    }

    file.close();
    return SUCCESS;
  }
  
  return ERROR_READING_FILE;
}

// Описание:
//   Търси песен по нейното име в файла и ако съществува връща информация за нея:
int SearchSongByName(Song& song, const char* file_name, char* song_name) {
  ifstream file(file_name, ios::binary);

  if(file.is_open()) {
    while(!file.eof()) {
      file.read((char*)&song, sizeof(Song));
      
      if(file.bad()) {
	cerr << "Read failed from " << file_name << "\n";
	file.close();
	return ERROR_READING_FILE;
      }
      
      // Ако сме намерили песента с това име:
      if(!strcmp(song.name, song_name)) {
	file.close();
	return SUCCESS;
      }
    }
  }
  return ERROR_READING_FILE;
}

int main() {  
  const char *file_name = "songs.bin";

  int songs_count;
  cout << "Enter number of songs to be stored: ";
  cin >> songs_count;
  
  // Въвеждаме песните една по една от стандартния вход:
  for(int i = 0; i < songs_count; i++) {
    Song song;
    cin.ignore();
    cin.getline(song.name, 50);
    cin >> song.length;
    WriteSongToFile(song, file_name);
  }

  Song song;

  char name[50];
  cin.ignore();
  cin.getline(name, 50);
  
  if(SearchSongByName(song, file_name, name) == SUCCESS) {
    cout << "Song name: "   << song.name;
    cout << "Song length: " << song.length;
  } else {
    cout << "Song " << name << " not found in the database :( \n";
  }
  
  return 0;
}
