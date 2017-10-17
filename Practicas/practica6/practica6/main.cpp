/*Practica 6: Star Microsystem
Equipo 4
- De Santiago Macías, Sergio Miguel
- Díaz Flores, Brandon
- González Gómez, Sebastián
- Hernández Orozco, Kenneth Michel
- Zúñiga Castellano, Francisco Jesús

Estructura de campos:
Metodo #2: Comenzar cada campo con un indicador de longitud
Estructura de registros:
Metodo #4: Colocar un delimitador al final de cada registro
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
//funcion en la cual se elige la opcion
int establecerOpcion();
//funcion para dar un contacto de alta
void darContactoDeAlta(std::fstream &);
//funcion para buscar un contacto y despues mostrarlo
void consultaIndividual(std::fstream &);
//funcion para mostrar contactos
void consultaGeneral(std::fstream &);
//funciono que imprime los contactos
void impresionDeContactos(unsigned const int &);

//le asignamos un valor a cada opcion
enum Opciones {DAR_CONTACTO_DE_ALTA = 1,CONSULTA_INDIVIDUAL,CONSULTA_GENERAL,TERMINAR};

int main(){
    //utilizamos la clase fstream y el archivo logico es de entrada y salida, con modo de escritura al final del archivo
    std::fstream archivoEntSal("contacts.txt",std::ios::in
                                            | std::ios::out
                                            | std::ios::app);
    //revisamos que el archivo se pueda abrir
    if(!archivoEntSal){
        std::cerr << "No se pudo abrir el archivo" << std::endl;
    }//fin de if

    int opcion;
    //pedimos una opcion en la funcion establecerOpcion y nos aseguramos que no sea igual a terminar
    while((opcion = establecerOpcion()) != TERMINAR){
        //reseteamos las banderas
        archivoEntSal.clear();
        //usamos la opcion antes dada para ir a la funcion.
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
            system("pause");
        }//fin de switch
    }//fin while
    //cerramos el archivo
    archivoEntSal.close();
    return 0;
    }//fin de main()

//funcion que regresa la opcion seleccionada
int establecerOpcion(){
    system("cls");
    int opcion;
    //mostrmos el menu
    std::cout << std::setw(80) <<"========================================================================" << std::endl;
    std::cout << std::setw(60) << "Menu - Agenda de Contactos" << std::endl;
    std::cout << std::setw(80) <<"========================================================================" << std::endl << std::endl;
    std::cout << "1.Alta de contacto" << std::endl
            << "2.Consulta Individual (Utilizar llave canonica)" << std::endl
            << "3.Consultas Generales" << std::endl
            << "4.Salir" << std::endl
            << "Elige tu opcion:" << std::endl;
    //guardamos la opcion en una variable
    std::cin >> opcion;
    //regresamos la opcion seleccionada
    return opcion;
    }//fin de funcion establecerOpcion()

//funcion para dar de alta un contacto
void darContactoDeAlta(std::fstream & archivoEntSal){
    system("cls");
    std::cout << std::setw(80) <<"========================================================================" << std::endl;
    std::cout << std::setw(50)<< "DANDO CONTACTO DE ALTA"<< std::endl;
    std::cout << std::setw(80) <<"========================================================================" << std::endl << std::endl;
    //creamos las variables
    std::string buffer(""),nombre(""),apellido(""),direccion(""),ciudad(""),colonia(""),correo("");
    int bytes = 0;

    //capturamos nombre en el archivo
    std::cin.ignore();
    std::cout << "Escribe tu nombre:";
    std::getline(std::cin,nombre);
    //se hace mayuscula la cadena
    std::transform(nombre.begin(), nombre.end()
    ,nombre.begin(), ::toupper);
    //guardamos el largo de la cadena
    bytes = nombre.size();
    //escribimos al archivo
    archivoEntSal << bytes;
    archivoEntSal.write(nombre.c_str(), bytes);

    //capturamos apellido en el archivo
    std::cout << "Escribe tu apellido: ";
    std::getline(std::cin, apellido);
    //se hace mayuscula la cadena
    std::transform(apellido.begin(), apellido.end()
    , apellido.begin(), ::toupper);
    bytes = apellido.size();
    //guardamos el largo de la cadena
    archivoEntSal << bytes;
    //escribimos al archivo
    archivoEntSal.write(apellido.c_str(), bytes);

    //capturamos direccion en el archivo
    std::cout << "Escribe tu direccion: ";
    std::getline(std::cin, direccion);
    //se hace mayuscula la cadena
    std::transform(direccion.begin(), direccion.end()
    ,direccion.begin(), ::toupper);
    bytes = direccion.size();
    //guardamos el largo de la cadena
    archivoEntSal << bytes;
    //escribimos al archivo
    archivoEntSal.write(direccion.c_str(), bytes);

    //capturamos colonia en el archivo
    std::cout << "Escribe tu colonia: ";
    std::getline(std::cin,colonia);
    //se hace mayuscula la cadena
    std::transform(colonia.begin(), colonia.end()
    ,colonia.begin(), ::toupper);
    bytes = colonia.size();
    //guardamos el largo de la cadena
    archivoEntSal << bytes;
    //escribimos al archivo
    archivoEntSal.write(colonia.c_str(), bytes);

    //capturamos ciudad en el archivo
    std::cout << "Escribe tu ciudad: ";
    std::getline(std::cin,ciudad);
    //se hace mayuscula la cadena
    std::transform(ciudad.begin(), ciudad.end()
    ,ciudad.begin(), ::toupper);
    bytes = ciudad.size();
    //guardamos el largo de la cadena
    archivoEntSal << bytes;
    //escribimos al archivo
    archivoEntSal.write(ciudad.c_str(), bytes);

    //capturamos correo en el archivo
    std::cout << "Escribe tu correo: ";
    std::getline(std::cin,correo);
    bytes = correo.size();
    //guardamos el largo de la cadena
    archivoEntSal << bytes;
    //escribimos al archivo
    archivoEntSal.write(correo.c_str(), bytes);

    //capturamos el separador de campo en el archivo
    archivoEntSal << "#";
    }//fin de funcion darContactoDeAlta()

//funcion para hacer una consulta de datos invidual
void consultaIndividual(std::fstream & archivoEntSal){
    system("cls");
    std::cin.ignore();
    std::string nombre, apellido, llaveCanonica;

    //pedimos los valores nombre y apellido para buscar el contacto
    std::cout << "Escribe el nombre: " << std::endl;
    std::getline(std::cin, nombre);
    std::cout << "Escribe el apellido: " << std::endl;
    std::getline(std::cin, apellido);

    //creamos la llave canonica y la hacemos mayuscula
    llaveCanonica = nombre+apellido;
    std::transform(llaveCanonica.begin(), llaveCanonica.end()
                    ,llaveCanonica.begin(), ::toupper);

    //acomodamos el puntero al principio del archivo
    archivoEntSal.seekg(std::ios::beg);
    //las variables representan los bytes que se guardaron al principio de cada campo y un contador
    int bytes,contador;
    //uno almacena la posicion de cada registro y otro la posicion de cada campo
    long posicionDeCampo,posicionDeRegistro;
    //variable para detectar el delimitador
    char delimitador;
    contador = 0;
    //obtenemos la posicion de nuestro puntero
    posicionDeRegistro = posicionDeCampo = archivoEntSal.tellg();
    //nos indicara si se encontro el registro buscado para imprimirlo
    bool imprimir = false;
    //nos indicara si se enontro un dato que sea igual a la llave canonica
    bool noSeEncontroDato = true;
    std::string nombreApellido = "";

    //iteramos en busca de los campos que cumplan la condicion
    while(!archivoEntSal.eof()){
        //si no se ha dado la orden de imprimir, almacenamos la posicion de puntero en una variable
        if(!imprimir){
         posicionDeCampo = archivoEntSal.tellg();
        }
        //si queremos imprimir, acomodaos el puntero en el campo que queremos imprimir
        else{
          archivoEntSal.seekg(posicionDeRegistro);
        }
        //checamos que no estemos leeyendo un delimitador
        archivoEntSal >> delimitador;
        if(delimitador != '#'){
            //imprimimos
            if(imprimir){
                //acomodamos el puntero al inicio del registro deseado
                archivoEntSal.seekg(posicionDeRegistro);
                //se lee el tamaño del campo
                archivoEntSal >> bytes;
                //creamos la variable donde guardaremos el registro
                char buffer[bytes] = "";
                //quitamos basura del arreglo
                memset(buffer, 0, bytes);
                //leemos el archivo
                archivoEntSal.read(buffer,bytes);
                //almacenamos la posicion de nuestro puntero
                posicionDeRegistro = archivoEntSal.tellg();
                //imprimimos el nombre de nuestra variable
                impresionDeContactos(contador);
                //imprimimos la variable que obtuvimos del archivo
                for(unsigned int i = 0; i < sizeof(buffer); i++){
                    std::cout << buffer[i];
                }//fin de for
                std::cout << std::endl;
                //reiniciamos el arreglo
                memset(buffer, 0, bytes);
                contador++;
                //if(contador == 6){imprimir = false;}
                }
            else{
                archivoEntSal.seekg(posicionDeCampo);
                //se lee el tamaño del campo
                archivoEntSal >> bytes;
                //creamos la variable donde guardaremos el registro
                char buffer[bytes] = "";
                //leemos del archivo el nombre y apellido
                archivoEntSal.read(buffer,bytes);
                //concatenamos el nombre y el apellido
                if(contador == 0 || contador == 1){
                    for(unsigned int i = 0; i < sizeof(buffer); i++){
                        nombreApellido += buffer[i];
                        }//fin de for
                    }//fin de if
                contador++;
            }//fin else
        }//fin de if(delimitador)
        else{
            //si ya se imprimio entonces dejamos de buscar y salimos del ciclo
            if(imprimir == true){
                break;
            }//fin de if;
            //si la llaveCanonica es igual al nombre concatenado con el apellido entrmos al if
            if(nombreApellido == llaveCanonica){
                imprimir = true;
                noSeEncontroDato = false;
             }//fin de if
            else {
                //inicializamos la variable nombreApellido para volver a usarla
                nombreApellido = "";
                //acomodamos nuestro puntero al inicio del siguiente registro
                posicionDeRegistro = archivoEntSal.tellg();
            }//fin de else
            contador = 0;
        }//fin de else
    }//fin de while
    if(noSeEncontroDato){
        std::cout << "No se encontro el contacto" << std::endl;
    }//fin de if (no se encontro dato)
    system("pause");
    }//fin de funcion consultaIndividual()

//funcion para ver todos los datos registrados en el archivo
void consultaGeneral(std::fstream & archivoEntSal){
    system("cls");
    //acomodamos el puntero al principio del archivo
    archivoEntSal.seekg(std::ios::beg);
    int bytes,contador;
    char delimitador;
    contador = 0;
    long posicion;
    //guardamos la posicion actual de nuestro puntero
    posicion = archivoEntSal.tellg();
    std::cout << std::setw(20) << "CONTACTOS" << std::endl << std::endl;
    std::cout << "============================================" << std::endl;
    //imprimir registros
    while(!archivoEntSal.eof()){
        //revisamos que no confundamos un delimitador con indicador de longitud
        posicion = archivoEntSal.tellg();
        archivoEntSal >> delimitador;
        //si no nos topamos con un delimitador seguimos buscando en los campos
        if(delimitador != '#'){
            archivoEntSal.seekg(posicion);
            //guardamos los bytes en una variable
            archivoEntSal >> bytes;
            //creamos la variable donde guardaremos el registro
            char buffer[bytes] = "";
            memset(buffer, 0, bytes);
            //leemos el archivo
            archivoEntSal.read(buffer,bytes);
            //revisamos en que posicion se encuentra nuestro puntero
            posicion = archivoEntSal.tellg();
            impresionDeContactos(contador);
            //imprimimos el archivo
            for(unsigned int i = 0; i < sizeof(buffer); i++){
                std::cout << buffer[i];
            }
            std::cout << std::endl;
            //reiniciamos el arreglo
            memset(buffer, 0, bytes);
            contador++;
            //si el contador llega a 6 significa que hay un nuevo registro
            if(contador == 6){
                 contador = 0;
                 std::cout << "============================================" << std::endl;
            }//fin de if(contador)
        }//fin de if(delimitador)
    }//fin de while
    system("pause");
}//fin de funcion consultaGeneral();

//funcion que imprime los datos de forma ordenada
void impresionDeContactos(unsigned const int & contador){
    if(contador == 0){
        std::cout  <<  "NOMBRE" << std::setw(7) << " = ";
    }
    else if(contador == 1){
        std::cout << "APELLIDO"<< std::setw(5) << " = ";
    }
    else if(contador == 2){
        std::cout  << "DIRECCION" << std::setw(4) << " = ";
    }
    else if(contador == 3){
        std::cout<<"COLONIA" << std::setw(6) << " = ";
    }
    else if(contador == 4){
        std::cout  <<"CIUDAD" << std::setw(7) << " = ";
    }
    else if(contador == 5){
        std::cout << "CORREO" << std::setw(7) << " = " ;
    }

}//fin  de funcion imprimeNombreDeVariable
