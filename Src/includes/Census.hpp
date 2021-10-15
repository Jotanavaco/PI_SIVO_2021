#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "../includes/FileSystem.hpp"

using namespace std;

class Census{

    private:
    //class attributes


    public:
    //Class defaul constructor
    Census();

    //Class default destructor
    ~Census();

    //Create a file of census in the filesystem
    void censusCreate(FileSystem* fileSystem, string censusFileName, char user, string permission);

    
    //Add data from file to Census
    void addDataFromCensus(FileSystem* fileSystem, string fileDirection, string fileName, char user, string permission);


    //Add a user in the census file
    void censusAppend(FileSystem* fileSystem, string censusFile, string data, char user, string permission);

    //Reads census file contents
    stringstream censusRead(FileSystem* fileSystem, string censusFileName, char user, string permission);

};