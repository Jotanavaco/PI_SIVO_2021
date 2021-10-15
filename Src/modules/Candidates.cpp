#include "../includes/Candidates.hpp"



Candidates::Candidates(){

}


Candidates::~Candidates(){

}





void Candidates::candidateCreate(FileSystem* fileSystem, string candidatesFileName, char user, string permission){

    fileSystem->create(candidatesFileName, user, permission);

}


void Candidates::candidateAppendVote(FileSystem* fileSystem, string candidateFile, char data, char user, string permission){

}


int Candidates::candidateVoteCount(FileSystem* fileSystem, string candidateFile, char user, string permission){

}

