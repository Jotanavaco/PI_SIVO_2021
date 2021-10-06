#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const int T_DIRECTORY = 3;
const int T_MEMORY_UNIT = 16;
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
  
  /*CENSUS variables*/
  
  
  
  /*CANDIDATE variables*/
  
  
  
  /*VOTES variables*/
  
  
  
};

class FileSystem {
  // class atributes
  private:
  char *memoryUnit;
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
  void append(string fileName, char data, char user, string permission);
  
  /*Writes to the file as indicated by the user (at the beginning or at the end)*/
  void write(string fileName, char data, int cursor, char user, string permission);

  /*Delete the indicated file*/
  void remove(string fileName, char user, string permission);

  /* If file exists and its open then reads all the data*/
  string read(string fileName, char user, string permission);
  
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
  
  
  
  
  
  
 
  
  
  
  
  
  
  /*METHODS TO CENSUS*/
  
  /*Creates a directory to storage a CENSUS file*/
  void createCENSUS(string directoryName, char user, string permission);
  
  
  /*Read a file and adds all the voters information to the memory*/
  void addDataFromFile(string fileDirection, string directoryName, char user, string permission);
  
  
  /*Add voter information to the memory*/
  void addVoterInformation(string directoryName, char user, string permission);
  
  
  /*Asks if a voter already voted*/
  bool votedAlready(string voterID, string directoryName, char user, string permission); 
  
  
  /*Returns the voter's information*/
  string readVoterInformation(string voterID, string directoryName, char user, string permission);
  
  
  
  
  
  
  /*METHODS TO CANDIDATES*/
  
  /*Creates a directory to storage a CANDIDATE file*/
  void createCandidate(string directoryName, char user, string permission);
  
  
  
  
  
  
  
  /*METHODS TO VOTES*/
  
  /*Creates a directory to storage a VOTES file*/
  void createVotes(string directoryName, char user, string permission);
  
  
  
};
