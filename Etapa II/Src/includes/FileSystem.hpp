#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

const int T_DIRECTORY = 6;
const int T_MEMORY_UNIT = 200;
const int ARRAY_SIZE = 6;
const int END_OF_FILE = -1;
const int FREE_BLOCK = -2;
const int FREE_MEMORY_NOT_FOUND = -3;
const int BLOCK_NOT_FOUND = -4;
const int RESERVED_BLOCK = -5;
const int BEGINNING_CURSOR = -6;
const int END_CURSOR = -7;

// contains the internal metadata of the file
struct Directory {
  int memoryBlock;
  string fileName; // Main variable. Need it to determine the directory nature
  time_t lastUpdateDate;
  bool isOpen;
  char user;
  string permission;
};

class FileSystem {
  // class atributes
  private:
  string *memoryUnit; //we need a string to manipulate different types of data easily
  Directory *directory;
  int *fatTable;
  int memoryUnitIndex;
  
  // permissions User arrays
  char userRead[ARRAY_SIZE] = {'B', 'C', 'D', 'E', 'F'};
  char userWrite[ARRAY_SIZE] = {'D', 'E', 'F'};
  char userRemove[ARRAY_SIZE] = {'E', 'F'};
  
  // permissions Group arrays
  char groupRead[ARRAY_SIZE] = {'B', 'C', 'D', 'E', 'F'};
  char groupWrite[ARRAY_SIZE] = {'C', 'D', 'E', 'F'};
  char groupRemove[ARRAY_SIZE] = {'F'};

  // permissions All arrays
  char allRead[ARRAY_SIZE] = {'B', 'C', 'D', 'E', 'F'};
  char allWrite[ARRAY_SIZE] = {'D', 'E', 'F'};
  char allRemove[ARRAY_SIZE] = {'F'};

  // class methods
  public:
  // class default Constructor, initialices all the values
  FileSystem();

  // class default destructor
  ~FileSystem();

  // basic class methods
  // Check if the file already exists, if not create it if you have the permission
  void create(string fileName, char user, string permission);

  /*if the file exists and it is not open, the methods will open it*/
  void open(string fileName);

  /*if the file exists and it is open it search an empty 
  block in the fat memory to write the data*/
  void append(string candidateFile, string votesFile, char data, char user, string permission);
 
  /*if the file exists and it is open it search an empty 
  block in the fat memory to write the data*/
  void censusAppend(string fileName, string lineData, char user, string permission);

  /*Add the vote to the vote file*/
  void appendVote(int directoryIndex, char data); 
  
  /*Writes to the file as indicated by the user (at the beginning or at the end)*/
  void write(string fileName, string votesFile, char data, int cursor, char user, string permission);

  /*Delete the indicated file*/
  void remove(string fileName, char user, string permission);

  /* If file exists and its open then reads all the data*/
  stringstream censusRead(string fileName, char user, string permission);

  /*returns the vote count*/
  int read(string fileName, char user, string permission);
  
  //if file exists and its open then it close 
  void close(string fileName);

  // methods call by basic class methods
  /* returns the index if the name asked exists in 
    the directory, otherwise returns BLOCK_NOT_FOUND*/
  int existingName(string fileName);

  /* returns the first block of the file from the directory,
    otherwise returns BLOCK_NOT_FOUND*/
  int searchFirstFileBlock(string fileName);

  /* returns the index of a free block of memory in the fatTable,
    otherwise returns FREE_MEMORY_NOT_FOUND*/
  int searchFreeFatBlock();
  
  /*returns two indexes of a block of free memory in fatTable,
    otherwise it returns FREE_MEMORY_NOT_FOUND*/
  bool searchTwoFreeFatBlock();

  /* returns the index of a free block of memory in the directory,
    otherwise returns FREE_MEMORY_NOT_FOUND*/
  int searchFreeDirectoryBlock();

  /* prints the directory*/
  void printDirectory();

  /* prints the memory Unit and fat Table*/
  void printUnitAndFatMemory();

  /* prints the file*/
  void printFile(string fileName);

  /*Check permission vectors*/
  bool checkPermission(char user, string permission
    , char permissionAction);

  bool checkPermissionArray(char user, char arrayToCheck[]);

  /*Delete data from file*/
  void removeFileData(int index);
  
  /* Read a file and adds all the voters information to the memory */
  void addDataFromCensus(string fileDirection, string fileName
  , char user, string permission);
};
