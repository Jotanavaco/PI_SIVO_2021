#include <iostream>
#include "Src/includes/FileSystem.hpp"

using namespace std;

int main() {
<<<<<<< HEAD
  cout << "hola" << endl;
  // FileSystem *fileSystem = new FileSystem();

  // //Creacion de archivos
  // fileSystem->create("prueba1.txt", 'D', "group");
  // fileSystem->create("prueba2.txt", 'D', "group");
  // fileSystem->create("prueba3.txt", 'D', "group");
  // fileSystem->create("prueba4.txt", 'D', "group");

  // //Abrir archivos
  // fileSystem->open("prueba1.txt");
  // fileSystem->open("prueba2.txt");
  // fileSystem->open("prueba3.txt");
  // fileSystem->open("prueba4.txt");

  // //Se escribe y se agrega en el archivo
  // fileSystem->append("prueba2.txt", 'h', 'D', "group");
  // fileSystem->append("prueba2.txt", 'o', 'D', "group");
  // fileSystem->append("prueba2.txt", 'l', 'D', "group");
  // fileSystem->append("prueba2.txt", 'a', 'D', "group");
  // fileSystem->write("prueba2.txt", 'H', -6, 'D', "group");

  // fileSystem->append("prueba3.txt", 'M', 'D', "group");
  // fileSystem->append("prueba3.txt", 'U', 'D', "group");
  // fileSystem->append("prueba3.txt", 'N', 'D', "group");
  // fileSystem->append("prueba3.txt", 'D', 'D', "group");
  // fileSystem->append("prueba3.txt", 'O', 'D', "group");

  // //Lectura de archivos
  // string datos = fileSystem->read("prueba2.txt", 'D', "group");
  // cout << "\nData: " << datos << "\n";

  // //Eliminar archivos
  // fileSystem->remove("prueba1.txt", 'A', "user");
  // fileSystem->remove("prueba2.txt", 'F', "user");

  // //Cerrar archivos
  // fileSystem->close("prueba1.txt");
  // fileSystem->close("prueba2.txt");
  // fileSystem->close("prueba3.txt");

  // //Llamar las impresiones
  // fileSystem->printDirectory();
  // fileSystem->printUnitAndFatMemory();
  // fileSystem->printFile("prueba1.txt");
=======
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
>>>>>>> master
}