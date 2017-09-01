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
#include <cstdio>

void printHeaderOfTable();
void printClient(const int, const std::string, const double);
void pressKeyToContinue();

int main()
{
    std::string fileName = "Cuentas.txt";

    std::ifstream myOutputFile(fileName, std::ios::in);

    if(!myOutputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        std::exit(1);
    }

    bool doWhile = true;
    std::string option;

    do {
        std::system("clear");
        std::cout << "Menú - Investigación de créditos" << std::endl << std::endl;
        std::cout << "1.- Mostrar cuentas con saldo en cero" << std::endl;
        std::cout << "2.- Mostrar cuentas con saldo acreedor" << std::endl;
        std::cout << "3.- Mostrar cuentas con saldo deudor" << std::endl;
        std::cout << "4.- Salir del programa" << std::endl << std::endl;
        std::cout << "Elige tu opcion: ";
        std::cin >> option;

        int cuenta;
        std::string nombre;
        double saldo;

        myOutputFile.clear();
        myOutputFile.seekg(0, std::ios::beg);

        switch(std::atoi(option.c_str())) {
        case 1:
            printHeaderOfTable();
            while(myOutputFile >> cuenta >> nombre >> saldo) {
                if(saldo == 0) {
                    printClient(cuenta, nombre, saldo);
                }
            }
            pressKeyToContinue();
            break;

        case 2:
            printHeaderOfTable();
            while(myOutputFile >> cuenta >> nombre >> saldo) {
                if(saldo < 0) {
                    printClient(cuenta, nombre, saldo);
                }
            }
            pressKeyToContinue();
            break;

        case 3:
            printHeaderOfTable();
            while(myOutputFile >> cuenta >> nombre >> saldo) {
                if(saldo > 0) {
                    printClient(cuenta, nombre, saldo);
                }
            }
            pressKeyToContinue();
            break;

        case 4:
            doWhile = !doWhile;
            break;

        default:
            std::system("clear");
            std::cin.ignore(254, '\n');
            std::cout << "Error" << std::endl << "Elija una opción correcta." << std::endl;
            pressKeyToContinue();
        }
    } while(doWhile);

    return 0;
}

void printHeaderOfTable() {
    std::system("clear");
    std::cin.ignore(254, '\n');
    std::cout << std::left << std::setw(11) << "CUENTA"
              << std::setw(13) << "NOMBRE"
              << std::setw(10) << std::right << "SALDO" << std::endl << std::endl
              << std::fixed << std::showpoint;
}

void printClient(const int cuenta, const std::string nombre, const double saldo) {
    std::cout << std::left << std::setw(11) << cuenta
              << std::setw(13) << nombre
              << std::setw(10) << std::setprecision(2) << std::right << saldo << std::endl;
}

void pressKeyToContinue() {
    std::cout << std::endl << "Presione ENTER para continuar...";
    std::getchar();
}

