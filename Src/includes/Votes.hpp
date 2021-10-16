#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "../includes/FileSystem.hpp"

using namespace std;

class Votes{

    private:
    //class attributes


    public:
    //Class default constructor
    Votes();

    //Class default destructor
    ~Votes();

    //Create a file of votes in the filesystem
    void votesCreate(FileSystem* fileSystem, string votesFileName, char user, string permission);

    //Add a vote in the votes file
    void voteAppend(FileSystem* fileSystem, string voteFile, string data, char user, string permission);

    //Gets total count of votes in the file 
    int votesCount(FileSystem* fileSystem, string votesFileName, char user, string permission);

};