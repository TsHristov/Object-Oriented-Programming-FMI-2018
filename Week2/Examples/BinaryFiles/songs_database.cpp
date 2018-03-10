#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Song {
  char name[50];
  unsigned length; // in milliseconds
};

// Описание:
//     Записва един обект тип Employee във файл с име `file_name`.
bool WriteSongToFile(Song& song, const char* file_name) {
  ofstream file(file_name, ios::binary);

  if(file.is_open()) {
    // Записваме обекта song във двоичния файл:
    file.write((const char*)&song, sizeof(Song));

    // Проверяваме дали писането е било успешно:
    if(file.bad()) {
      cerr << "Writing to " << file_name << " failed\n";
      return false;
    }

    file.close();
    return true;
  }

  return false;
}

// Описание:
//     Прочита n-тата песен записана във файла:
bool ReadSongFromFile(Song& song, const char* file_name, int n) {
  ifstream file(file_name, ios::binary);

  if(file.is_open()) {
    // Позиционираме маркера за четене от файла, като
    // прескачаме n-1 Employee структури спрямо началото на файла:
    file.seekg((n-1)*sizeof(Song), ios::beg);
    file.read((char*)&song, sizeof(Song));

    // Проверяваме дали успешно сме прочели служител от файла:
    if(file.bad()){
      cerr << "Reading from " << file_name << " failed\n";
      return false;
    }

    file.close();
    return true;
  }
  
  return false;
}

int main() {  
  const char *file_name = "songs.bin";

  int songs_count;
  cout << "Enter number of songs to be stored:";
  cin >> songs_count;

  // Въвеждаме песните една по една от стандартния вход (конзолата):
  for(int i = 0; i < songs_count; i++) {
    Song song;
    cin.ignore();
    cin.getline(song.name, 50);
    cin >> song.length;
    WriteSongToFile(song, file_name);
  }

  Song song;
  int nth_song;
  cout << "Enter a number from 1 - " << songs_count
       << " to display information for the song:";
  cin >> nth_song;
  ReadSongFromFile(song, file_name, nth_song);

  cout << "Song No: " << nth_song << " info:\n";
  cout << song.name   << "\n";
  cout << song.length << "\n";
  
  return 0;
}
