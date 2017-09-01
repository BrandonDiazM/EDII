#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

void showLine(const std::string, const int, const std::string);

int main() {
    std::string fileName = "Personas.txt";

    std::string name;
    int age;
    std::string sport;

    std::ifstream myOutputFile;
    myOutputFile.open(fileName, std::ios::in);

    if(!myOutputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo '" << fileName << "." << std::endl;
    }

    std::cout << std::left << std::setw(11) << "Nombre"
              << std::setw(13) << "Edad"
              << std::setw(7) << "Deporte" << std::endl << std::fixed << std::showpoint;

    while(myOutputFile >> name >> age >> sport) {
        showLine(name, age, sport);
    }

    myOutputFile.close();
    return 0;
}

void showLine(const std::string name, const int age, const std::string sport) {
    std::cout << std::left << std::setw(11) << name
              << std::setw(13) << age
              << std::setw(7) << sport << std::endl;
}

