#include "../includes/Census.hpp"




    //Class defaul constructor
    Census::Census(){

    }

    //Class default destructor
    Census::~Census(){

    }

    //Create a file of census in the filesystem
    void Census::censusCreate(FileSystem* fileSystem, string censusFileName, char user, string permission){

        fileSystem->create(censusFileName, user, permission);

    }

    //Add data from file to Census
    //THIS METHOD NEED A CHANGE. READ FILE HAPPENS IN THIS LEVEL
    void Census::addDataFromCensus(FileSystem* fileSystem, string fileDirection, string fileName, char user, string permission){

        fileSystem->addDataFromCensus(fileDirection, fileName, user, permission);

    }



    //Add a user in the census file
    void Census::censusAppend(FileSystem* fileSystem, string censusFile, string data, char user, string permission){

        fileSystem->append(censusFile, data, user, permission);

    }

    //Reads census file contents
    stringstream Census::censusRead(FileSystem* fileSystem, string censusFileName, char user, string permission){

        stringstream datos = fileSystem->read(censusFileName, user, permission);

        return datos;

    }