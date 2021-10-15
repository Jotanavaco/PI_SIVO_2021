#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Census{

    //class attributes


    //Class defaul constructor
    Census();

    //Class default destructor
    ~Census();

    //Create a file of candidates in the filesystem
    void censusCreate(string censusFileName, char user, string permission);

    //Add a candidate in the candidates file
    void censusAppend(string censusFile, char user, string permission);

    //Reads census file contents
    stringstream censusRead(string censusFileName, char user, string permission);

};