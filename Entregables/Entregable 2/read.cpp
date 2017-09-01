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
#include <cstring>

void showLine(const int, const std::string, const double);

int main() {
    std::string fileName = "Cuentas.txt";

    std::ifstream myOutputFile(fileName, std::ios::in);

    if(!myOutputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo '" << fileName << "." << std::endl;
    }

    int cuenta;
    std::string nombre;
    double saldo;

    std::cout << std::left << std::setw(11) << "CUENTA"
              << std::setw(13) << "NOMBRE"
              << std::setw(10) << std::right << "SALDO" << std::endl << std::fixed << std::showpoint;

    while(myOutputFile >> cuenta >> nombre >> saldo) {
        showLine(cuenta, nombre, saldo);
    }
    
    return 0;
}

void showLine(const int cuenta, const std::string nombre, const double saldo) {
    std::cout << std::left << std::setw(11) << cuenta
              << std::setw(13) << nombre
              << std::setw(10) << std::setprecision(2) << std::right  << saldo << std::endl;
}

