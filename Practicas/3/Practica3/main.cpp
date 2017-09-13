#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>

#include "client.hpp"

void printHeaderOfTable();
void printClient(Client);

int main()
{
    std::string fileName = "Credito.txt";

    std::ifstream creditInput(fileName, std::ios::in | std::ios::binary);

    if(!creditInput) {
        std::cerr << "No se pudo abrir el archivo" << std::endl;
        std::exit(1);
    }

    Client client;

    printHeaderOfTable();

    while(!creditInput.eof()) {
        creditInput.read(reinterpret_cast<char *>(&client), sizeof(Client));
        if(client.getAccountNumber() > 0) {
            printClient(client);
        }
    }

    return 0;
}

void printHeaderOfTable() {
    std::cout << std::left << std::setw(7) << "CUENTA"
              << std::setw(13) << "NOMBRE"
              << std::setw(13) << "APELLIDO"
              << std::setw(12) << std::right << "SALDO"
              << std::fixed << std::showpoint
              << std::endl << std::endl;
}

void printClient(Client client) {
    std::cout << std::left << std::setw(7) << client.getAccountNumber()
              << std::setw(13) << client.getName()
              << std::setw(13) << client.getLastName()
              << std::setw(12) << std::setprecision(2)
              << std::right << client.getBalance() << std::endl;
}
