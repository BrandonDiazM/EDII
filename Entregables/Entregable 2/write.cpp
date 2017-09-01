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

int main() {
    std::string fileName = "Cuentas.txt";

    std::ofstream myFile(fileName, std::ios::out);

    if(!myFile.is_open()) {
        std::cout << "El archivo '" << fileName << "' no se puede abrir." << std::endl;
    }

    int cuenta;
    std::string nombre;
    double saldo;

    std::cout << "Escriba el número de cuenta, nombre y saldo." << std::endl
              << "Escriba fin de archivo para terminar la entrada." << std::endl
              << "> ";
              
    while(std::cin >> cuenta >> nombre >> saldo) {
        myFile << cuenta << ' ' << nombre << ' ' << saldo << std::endl;
        std::cout << "> ";
    }

    return 0;
}