#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "contacto.h"

int establecerOpcion();
void darContactoDeAlta(std::fstream &);
void consultaIndividual(std::fstream &);
void consultaGeneral(std::fstream &);

enum Opciones {DAR_CONTACTO_DE_ALTA = 1,CONSULTA_INDIVIDUAL,CONSULTA_GENERAL,TERMINAR};

int main(){

    std::fstream archivoEntSal("contactos.txt",std::ios::in
                                            | std::ios::out
                                            | std::ios::app);
    //revisamos que el archivo se pueda abrir
    if(!archivoEntSal){
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }//fin de if

    int opcion;
    //pedimos una opcion para ir a la funcion deseada
    while((opcion = establecerOpcion()) != TERMINAR){
        archivoEntSal.clear();
        switch(opcion){
            case DAR_CONTACTO_DE_ALTA:
            darContactoDeAlta(archivoEntSal);
            break;
            case CONSULTA_INDIVIDUAL:
            consultaIndividual(archivoEntSal);
            break;
            case CONSULTA_GENERAL:
            consultaGeneral(archivoEntSal);
            break;
            default:
            std::cerr << "opcion seleccionada incorrecta"<< std::endl;

        }//fin de switch

    }//fin while

    archivoEntSal.close();
    return 0;
    }//fin de main()

//funcion para elegir la opcion deseada
int establecerOpcion(){
    int opcion;

    std::cout << "1.Dar contacto de alta" << std::endl
            << "2.Consulta Individual" << std::endl
            << "3.Consultas Generales" << std::endl
            << "4.Salir" << std::endl
            << "Elige tu opcion:" << std::endl;
    std::cin >> opcion;

    return opcion;
    }//fin de funcion establecerOpcion()

//funcion para dar de alta un contacto
void darContactoDeAlta(std::fstream & archivoEntSal){
    //creamos las variables
    std::string buffer(""),nombre(""),apellido(""),direccion(""),ciudad(""),estado(""),codigoPostal("");
    int bytes = 0;

    //capturamos los datos de la persona
    std::cin.ignore();
    std::cout << "Escribe tu nombre:";
    std::getline(std::cin,nombre);
    std::transform(nombre.begin(), nombre.end()
    ,nombre.begin(), ::toupper);
    bytes += nombre.size();

    std::cout << "Escribe tu apellido: ";
    std::getline(std::cin, apellido);
    std::transform(apellido.begin(), apellido.end()
    , apellido.begin(), ::toupper);
    bytes += apellido.size();

    std::cout << "Escribe tu direccion: ";
    std::getline(std::cin, direccion);
    std::transform(direccion.begin(), direccion.end()
    ,direccion.begin(), ::toupper);
    bytes += direccion.size();

    std::cout << "Escribe tu ciudad: ";
    std::getline(std::cin,ciudad);
    std::transform(ciudad.begin(), ciudad.end()
    ,ciudad.begin(), ::toupper);
    bytes += ciudad.size();

    std::cout << "Escribe tu estado: ";
    std::getline(std::cin,estado);
    std::transform(estado.begin(), estado.end()
    ,estado.begin(), ::toupper);
    bytes += estado.size();

    std::cout << "Escribe tu codigo postal: ";
    std::getline(std::cin,codigoPostal);
    bytes += codigoPostal.size();

    //se agregan 6 ya que son los 6 separadores que usamos abajo
    bytes += 6;

    //escribimos el largo del string al archivo
    archivoEntSal << bytes;

    //concatenamos las cadenas en una
    buffer += nombre + "|" + apellido + "|" + direccion
             + "|" + ciudad  + "|" + estado + "|" + codigoPostal + "|";
    std::cout << buffer << std::endl;
    //escribimos al archivo
    archivoEntSal.write(buffer.c_str(), bytes);
    }//fin de funcion darContactoDeAlta()

//funcion para hacer una consulta de datos invidual
void consultaIndividual(std::fstream & archivoEntSal){
    std::cin.ignore();
    std::string nombre, apellido, llaveCanonica;

    //pedimos los valores para buscar los datos
    std::cout << "Escribe el nombre: " << std::endl;
    std::getline(std::cin, nombre);
    std::cout << "Escribe el apellido: " << std::endl;
    std::getline(std::cin, apellido);

    //creamos la llave canonica
    llaveCanonica = nombre+apellido;
    std::transform(llaveCanonica.begin(), llaveCanonica.end()
                    ,llaveCanonica.begin(), ::toupper);

    std::cout << llaveCanonica;

    //leemos el archivo en busca del dato

    //acomodamos el puntero al principio del archivo
    archivoEntSal.seekg(std::ios::beg);
    //los bytes que se guardaron al principio de cada registro
    int bytes,contador;
    contador = 0;
    std::string nombreApellido = "";
    //iteramos en busca de los campos que cumplan la condicion
    while(!archivoEntSal.eof()){
        //guardamos los bytes en una variable
        archivoEntSal >> bytes;
        //creamos la variable donde guardaremos el registro
        char buffer[bytes] = "";
        //leemos el archivo
        archivoEntSal.read(buffer, sizeof(buffer));
        nombreApellido =  "";
        //iteramos en el buffer para buscar los dos elementos que forma la llave canonica
        for(int i = 0; i < bytes; i++){
            if(buffer[i] == '|'){
                contador++;
            }//fin de if
            if(contador == 2){
                break;
            }
            if(buffer[i] !=  '|'){
            nombreApellido += buffer[i];
            }
        }//fin de for
       //comparamos los datos para ver si coincide con la llave canonica
       if(nombreApellido == llaveCanonica){
           std::cout << buffer << std::endl;
           break;

       }//fin de if
    }//fin de while

    }//fin de funcion consultaIndividual()

//funcion para ver todos los datos registrados en el archivo
void consultaGeneral(std::fstream & archivoEntSal){
    //acomodamos el puntero al principio del archivo
    archivoEntSal.seekg(std::ios::beg);
    //los bytes que se guardaron al principio de cada registro
    int bytes;
    //imprimir registros
    while(!archivoEntSal.eof()){
        //guardamos los bytes en una variable
        archivoEntSal >> bytes;
        //creamos la variable donde guardaremos el registro
        char buffer[bytes] = "";
        //leemos el archivo
        archivoEntSal.read(buffer, sizeof(buffer));
        //imprimimos el archivo
        std::cout << buffer << std::endl;
    }//fin de while
}//fin de funcion consultaGeneral();
