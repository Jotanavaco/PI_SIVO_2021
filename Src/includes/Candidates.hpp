#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "../includes/FileSystem.hpp"

using namespace std;

class Candidates{

    private:
    //class attributes




    public:

    //Class defaul constructor
    Candidates();

    //Class default destructor
    ~Candidates();

    //Create a file that represent a candidate in the filesystem
    void candidateCreate(FileSystem* fileSystem, string candidatesFileName, char user, string permission);

    //Register a vote in the candidate file
    void candidateAppendVote(FileSystem* fileSystem, string candidateFile, string data, char user, string permission);

    //Get total count of votes for this candidate
    int candidateVoteCount(FileSystem* fileSystem, string candidateFile, char user, string permission);

};