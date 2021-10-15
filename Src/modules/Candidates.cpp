#include "../includes/Candidates.hpp"



Candidates::Candidates(){

}


Candidates::~Candidates(){

}





void Candidates::candidateCreate(FileSystem* fileSystem, string candidatesFileName, char user, string permission){

    fileSystem->create(candidatesFileName, user, permission);

}


void Candidates::candidateAppendVote(FileSystem* fileSystem, string candidateFile, string data, char user, string permission){

    fileSystem->append(candidateFile, data, user, permission);

}


int Candidates::candidateVoteCount(FileSystem* fileSystem, string candidateFile, char user, string permission){

    int voteCount = fileSystem->fileCount(candidateFile, user, permission);

    return voteCount;
}



