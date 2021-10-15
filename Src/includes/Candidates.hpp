#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Candidates{

    //class attributes


    //Class defaul constructor
    Candidates();

    //Class default destructor
    ~Candidates();

    //Create a file of candidates in the filesystem
    void candidatesCreate(string candidatesFileName, char user, string permission);

    //Add a candidate in the candidates file
    void candidateAppend(string candidateFile, char user, string permission);

};