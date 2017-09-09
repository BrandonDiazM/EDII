/*
Equipo 4
- De Santiago Macías, Sergio Miguel
- Díaz Flores, Brandon
- González Gómez, Sebastián
- Hernández Orozco, Kenneth Michel
- Zúñiga Castellano, Francisco Jesús
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "client.hpp"

int main()
{
    // Práctica 2
    std::string filename = "Credito.txt";
    std::ofstream creditOut(filename, std::ios::binary);
    if(!creditOut) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        std::exit(1);
    } //if

    Client client;
    for(int i = 0; i < 100; ++i) {
        creditOut.write(reinterpret_cast<const char *>(&client), sizeof(Client));
    } // for

    return 0;
} // Main
