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
    // Ejercicio: Cómo escribir en un archivo de acceso aleatorio
    std::string filename = "Credito.txt";
    std::ofstream creditOut(filename, std::ios::binary);
    if(!creditOut) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        std::exit(1);
    }

    int accountNumber;
    std::string lastName;
    std::string name;
    double balance;

    Client client;

    std::cout << "Escriba el número de cuenta (Entre 1 y 100, 0 para terminar la entrada)" << std::endl;
    std::cout << "> ";
    std::cin >> accountNumber;

    client.setAccountNumber(accountNumber);

    while(client.getAccountNumber() >= 1 && client.getAccountNumber() <= 100) {
        std::cout << "Teclea el apellido, primer nombre, saldo" << std::endl;
        std::cout << "> ";
        std::cin >> std::setw(15) >> lastName;
        std::cin >> std::setw(10) >> name;
        std::cin >> balance;

        client.setLastName(lastName);
        client.setName(name);
        client.setBalance(balance);

        creditOut.seekp((client.getAccountNumber() - 1) * sizeof(Client));

        creditOut.write(reinterpret_cast<const char *>(&client), sizeof(Client));

        std::cout << "Escriba el número de cuenta (Entre 1 y 100, 0 para terminar la entrada)" << std::endl;
        std::cout << "> ";
        std::cin >> accountNumber;

        client.setAccountNumber(accountNumber);
    } // While

    return 0;
} // Main
