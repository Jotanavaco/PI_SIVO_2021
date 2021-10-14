#include <iostream>
#include "Src/includes/FileSystem.hpp"

using namespace std;

int main() {
  FileSystem *fileSystem = new FileSystem();

  // Creacion de archivo del padrón
  fileSystem->create("Census", 'D', "group");
  // Abrir archivo padrón
  fileSystem->open("Census");
  
  // Escritura del padrón (census)
  fileSystem->addDataFromCensus("Docs/Census.txt", "Census", 'D', "group");

  // Actualización del padrón (escritura manual)
  /*Formato de ingreso; 101710541,301022, ,20300618,00000,DANIEL                        ,ROBLES                    ,VENEGAS              .f*/
  fileSystem->censusAppend("Census", "Padron de prueba", 'D', "group");

    // Lectura del padrón (census)
  stringstream datos = fileSystem->censusRead("Census", 'D', "group");
  cout << "\nCensus data: \n" << datos.str() << "\n";

  // Creación archivo de votos
  fileSystem->create("GeneralVotes", 'D', "group");
  fileSystem->create("JuanitoMora", 'D', "group");
  fileSystem->create("EdgarSilva", 'D', "group");
  fileSystem->create("MaritoMortadela", 'D', "group");

  //Abrir archivos de votos
  fileSystem->open("GeneralVotes");
  fileSystem->open("JuanitoMora");
  fileSystem->open("EdgarSilva");
  fileSystem->open("MaritoMortadela");

  // Escritura de votos
  fileSystem->append("JuanitoMora", "GeneralVotes", '1', 'D', "group");
  fileSystem->append("JuanitoMora", "GeneralVotes", '1', 'D', "group");
  fileSystem->write("JuanitoMora", "GeneralVotes", '1', -7, 'D', "group");

  fileSystem->append("EdgarSilva", "GeneralVotes", '1', 'D', "group");
  fileSystem->append("EdgarSilva", "GeneralVotes" , '1', 'D', "group");
  fileSystem->append("EdgarSilva", "GeneralVotes", '1', 'D', "group");
  fileSystem->write("EdgarSilva", "GeneralVotes", '1', -7, 'D', "group");

  fileSystem->append("MaritoMortadela", "GeneralVotes", '1', 'D', "group");

  // Lectura de votos
   int votosGenerales = fileSystem->read("GeneralVotes", 'D', "group");
  cout << "\nCantidad votos Generales: " << votosGenerales << endl;
   int votos1 = fileSystem->read("JuanitoMora", 'D', "group");
  cout << "Cantidad votos Juanito Mora: " << votos1 << endl;
   int votos2 = fileSystem->read("EdgarSilva", 'D', "group");
  cout << "Cantidad votos Edgar Silva: " << votos2 << endl;
  int votos3 = fileSystem->read("MaritoMortadela", 'D', "group");
  cout << "Cantidad votos Marito Mortadela: " << votos3 << endl;

  //Eliminar archivos
  // fileSystem->remove("prueba1.txt", 'A', "user");
  // fileSystem->remove("JuanitoMora", 'F', "user");

  //Cerrar archivos
  fileSystem->close("JuanitoMora");
  fileSystem->close("GeneralVotes");

  //Llamar las impresiones
  fileSystem->printDirectory();
  fileSystem->printUnitAndFatMemory();
}