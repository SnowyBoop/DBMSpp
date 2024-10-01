#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

std::string loadDB(std::string dbName) {
  std::cout << "starting db load\n";
  std::ifstream database;
  database.open (dbName);

  if(database.is_open()) {

    std::string rawDB = "file";

    getline(database,rawDB);

    return rawDB;
  }
  
  return "error";
}

void createDB (std::string name) {
  std::cout << "starting db create\n";
  std::ofstream newDB;
  newDB.open (name);
  newDB << "test meow";
  newDB.close();

  return;
}

int main() {

  std::cout << "starting...\n";

  createDB("test.lul");
  std::string returnVal;
  returnVal = loadDB("test.lul");
  
  std::cout << returnVal << "\n";

  
  return 0;

}
