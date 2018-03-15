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
//     Записва един обект тип Song във файл с име `db_name`.
int write_song(Song& song, const char* db_name) {
  // ios::app - защото искаме да добавяме новия запис към базата от данни:
  ofstream database(db_name, ios::binary | ios::app);

  if(database.is_open()) {
    // Записваме обекта song в двоичния файл:
    database.write((const char*)&song, sizeof(Song));

    // Проверяваме дали писането е било успешно:
    if(database.bad()) {
      cerr << "Writing failed in: " << db_name;
      database.close();
      return ERROR_WRITING_FILE;
    }

    database.close();
    return SUCCESS;
  }

  return ERROR_OPENING_FILE;
}

// Описание:
//     Прочита n-тата песен записана във файла:
int read_song(Song& song, const char* db_name, int n) {
  ifstream database(db_name, ios::binary);
  
  if(database.is_open()) {
    // Позиционираме маркера за четене от файла, като
    // прескачаме n-1 структури спрямо началото на файла:
    database.seekg((n-1)*sizeof(Song), ios::beg);
    database.read((char*)&song, sizeof(Song));

    // Проверяваме дали успешно сме прочели песен от файла:
    if(database.bad()){
      cerr << "Reading failed in: " << db_name;
      database.close();
      return ERROR_READING_FILE;
    }

    database.close();
    return SUCCESS;
  }
  
  return ERROR_OPENING_FILE;
}

// Описание:
//   Намира песен (ако съществува) по нейното име във файла и ако съществува връща информация за нея:
int find_song_by_name(Song& song, const char* db_name, char* song_name) {
  ifstream database(db_name, ios::binary);
  
  if(database.is_open()) {
    while(!database.eof()) {

      database.read((char*)&song, sizeof(Song));
      
      if(database.bad()) {
	cerr << "Read failed in: " << db_name << "\n";
	database.close();
	return ERROR_READING_FILE;
      }
      
      // Ако сме намерили песента с това име:
      if(!strcmp(song.name, song_name)) {
	database.close();
	return SUCCESS;
      }
    }
  }
  
  return ERROR_OPENING_FILE;
}

// Описание:
//    Намира песента в базата от данни с най-кратка продължителност:
int find_min_length_song(Song& song, const char* db_name) {
  ifstream database(db_name, ios::binary);
  
  Song min_length_song;
  
  if(database.is_open()) {

    database.read((char*)&song, sizeof(Song));

    if (database.bad()) {
      cerr << "Read failed in: " << db_name;
      database.close();
      return ERROR_READING_FILE;
    }

    min_length_song = song;
    
    while(!database.eof()) {

      database.read((char*)&song, sizeof(Song));

      if(database.bad()) {
	cerr << "Read failed in: " << db_name;
	database.close();
	return ERROR_READING_FILE;
      }

      // Ако дължината на току-що прочетената песен
      // е по-малка от до сега намерената, то това е
      // новата песен с най-малка продължителност:
      if(song.length < min_length_song.length) {
	min_length_song = song;
      }
    }

    // Тъй като връщаме резултат,
    // чрез параметъра на функцията song,
    // копираме намерената минимална песен в song:
    song = min_length_song;

    database.close();
    
    return SUCCESS;
  }

  return ERROR_OPENING_FILE;
}

// Описание:
//    Изкарва информация за песните в базата от данни в текстови формат, с произволен разделител.
// Връщан резултат:
//    int - код на завършване (RETURN_CODE)
int generate_report(const char* db_name, const char* songs_report_name, const char& delimeter = ' ') {
  // Отваряме база от данни за четене (ifstream):
  ifstream database(db_name, ios::binary);
  // Отваряме текстовия файл за репорт за писане (ofstream),
  // + ios::trunc, за да изтрие предишно съдържание на файла,
  // ако такова съществува:
  ofstream report(songs_report_name, ios::trunc);

  if (database.is_open() && report.is_open()) {
    // Четем базата от данни структура по структура:
    while (!database.eof()) {
      Song song;
      
      database.read((char*)&song, sizeof(Song));

      if (database.eof()) {
	break;
      }
      
      if (database.bad()) {
	cerr << "Read failed in: " << db_name;
	database.close();
	report.close();
	return ERROR_READING_FILE;
      }

      // Записваме структурата в текстовия файл с подходящия разделител (delimeter):
      report << song.name << delimeter << song.length << "\n";

      if (report.bad()) {
	cerr << "Write failed in: " << songs_report_name;
        database.close();
	report.close();
	return ERROR_WRITING_FILE;
      }
    }
  }

  database.close();
  report.close();

  return ERROR_OPENING_FILE;
}

int main() {  
  const char *db_name = "songs.db";

  int songs_count;
  cout << "Enter number of songs to be stored: ";
  cin >> songs_count;
  
  // Въвеждаме песните една по една от стандартния вход:
  for(int i = 0; i < songs_count; i++) {
    Song song;
    cin.ignore();
    cin.getline(song.name, 50);
    cin >> song.length;
    write_song(song, db_name);
  }

  Song song;

  if(find_min_length_song(song, db_name) == SUCCESS) {
    cout << "Minimum length song info: \n";
    cout << "Song name: " << song.name << "\n";
    cout << "Song length: " << song.length << "\n";
  } else {
    cout << "Failure reading from " << db_name << "\n";
  }

  const char* report_name = "songs.csv";

  generate_report(db_name, report_name, ',');
  
  return 0;
}
