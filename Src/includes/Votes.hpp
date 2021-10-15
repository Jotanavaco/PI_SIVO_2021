#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Votes{

    //class attributes


    //Class defaul constructor
    Votes();

    //Class default destructor
    ~Votes();

    //Create a file of candidates in the filesystem
    void votesCreate(string votesFileName, char user, string permission);

    //Add a candidate in the candidates file
    void voteAppend(string voteFile, char user, string permission);

    //Gets total count of votes in the file 
    int votesCount(string votesFileName, char user, string permission);

};