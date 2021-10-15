#include <iostream>
#include "Src/includes/FileSystem.hpp"
#include "Src/includes/Candidates.hpp"

using namespace std;

int main() {
  FileSystem *fileSystem = new FileSystem();
  Candidates *candidates = new Candidates();
  //Census *census = new Census();
  //Votes *votes = new Votes();


  // Creacion de archivo del padrón
  fileSystem->create("Census", 'D', "group");
  //census->censusCreate(fileSystem, "Census", 'D', "group");

  
  // Abrir archivo padrón
  fileSystem->open("Census");
  //Might need a security class to manage this
  

  // Escritura del padrón (census)
  fileSystem->addDataFromCensus("Docs/Census.txt", "Census", 'D', "group");
  //Census->addDataFromCensus(fileSystem, "Docs/Census.txt", "Census", 'D', "group");

  // Actualización del padrón (escritura manual)
  /*Formato de ingreso; 101710541,301022, ,20300618,00000,DANIEL                        ,ROBLES                    ,VENEGAS              .f*/
  fileSystem->append("Census", "Padron de prueba", 'D', "group");
  //census->censusAppend(fileSystem, "Census", "Padron de prueba", 'D', "group");


  // Lectura del padrón (census)
  stringstream datos = fileSystem->censusRead("Census", 'D', "group");
  //stringstream datos = census->censusRead(fileSystem, "Census", 'D', "group");
  cout << "\nCensus data: \n" << datos.str() << "\n";



  // Creación archivo de votos
  fileSystem->create("GeneralVotes", 'D', "group"); 
  //votes->votesCreate(fileSystem, "GeneralVotes", 'D', "group")


  //fileSystem->create("JuanitoMora", 'D', "group");
  candidates->candidateCreate(fileSystem, "JuanitoMora", 'D', "group");


  //fileSystem->create("EdgarSilva", 'D', "group");
  candidates->candidateCreate(fileSystem, "EdgarSilva", 'D', "group");


  //fileSystem->create("MaritoMortadela", 'D', "group");
  candidates->candidateCreate(fileSystem, "MaritoMortadela", 'D', "group");




  //Abrir archivos de votos
  fileSystem->open("GeneralVotes");
  fileSystem->open("JuanitoMora");
  fileSystem->open("EdgarSilva");
  fileSystem->open("MaritoMortadela");
  //Might need a security class to manage this



  // Escritura de votos
  //fileSystem->append("JuanitoMora", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "JuanitoMora", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");


  //fileSystem->append("JuanitoMora", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "JuanitoMora", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");


  //fileSystem->write("JuanitoMora", "1", -7, 'D', "group");
  candidates->candidateAppendVote(fileSystem, "JuanitoMora", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");





  //fileSystem->append("EdgarSilva", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "EdgarSilva", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");


  //fileSystem->append("EdgarSilva", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "EdgarSilva", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");

  //fileSystem->append("EdgarSilva", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "EdgarSilva", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");

  //fileSystem->write("EdgarSilva", "1", -7, 'D', "group");
  candidates->candidateAppendVote(fileSystem, "EdgarSilva", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");




  //fileSystem->append("MaritoMortadela", "1", 'D', "group");
  candidates->candidateAppendVote(fileSystem, "MaritoMortadela", "1", 'D', "group");
  //votes->voteAppend(fileSystem, "GeneralVotes", "1", 'D', "group");




  // Lectura de votos
  int votosGenerales = fileSystem->fileCount("GeneralVotes", 'D', "group");
  // int votosGenerales = votes->votesCount("GeneralVotes", 'D', "group");
  cout << "\nCantidad votos Generales: " << votosGenerales << endl;


  //int votos1 = fileSystem->fileCount("JuanitoMora", 'D', "group");
  int votos1 = candidates->candidateVoteCount(fileSystem, "JuanitoMora", 'D', "group");
  cout << "Cantidad votos Juanito Mora: " << votos1 << endl;
   
    
  //int votos2 = fileSystem->fileCount("EdgarSilva", 'D', "group");
  int votos2 = candidates->candidateVoteCount(fileSystem, "EdgarSilva", 'D', "group");
  cout << "Cantidad votos Edgar Silva: " << votos2 << endl;


  //int votos3 = fileSystem->fileCount("MaritoMortadela", 'D', "group");
  int votos3 = candidates->candidateVoteCount(fileSystem, "MaritoMortadela", 'D', "group");
  cout << "Cantidad votos Marito Mortadela: " << votos3 << endl;

  //Eliminar archivos
  // fileSystem->remove("prueba1.txt", 'A', "user");
  // fileSystem->remove("JuanitoMora", 'F', "user");

  //Cerrar archivos
  fileSystem->close("JuanitoMora");
  fileSystem->close("GeneralVotes");
  //Might need a security class to manage this



  //Llamar las impresiones
  fileSystem->printDirectory();
  fileSystem->printUnitAndFatMemory();
}