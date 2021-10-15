#include "../includes/Votes.hpp"


    //Class default constructor
    Votes::Votes(){

    }

    //Class default destructor
    Votes::~Votes(){

    }

    //Create a file of votes in the filesystem
    void Votes::votesCreate(FileSystem* fileSystem, string votesFileName, char user, string permission){

        fileSystem->create(votesFileName, user, permission);

    }

    //Add a vote in the votes file
    void Votes::voteAppend(FileSystem* fileSystem, string voteFile, string data, char user, string permission){

        fileSystem->append(voteFile, data, user, permission);

    }

    //Gets total count of votes in the file 
    int Votes::votesCount(FileSystem* fileSystem, string votesFileName, char user, string permission){

        int votos = fileSystem->fileCount(votesFileName, user, permission);

        return votos;

    }