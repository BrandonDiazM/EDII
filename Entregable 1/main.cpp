#include <iostream>
#include <fstream>

int main() {
    std::string fileName = "Personas.txt";

    std::ofstream myFile;

    std::string name;
    int age;
    std::string sport;

    myFile.open(fileName, std::ios::out);

    if(!myFile.is_open()) {
        std::cout << "El archivo '" << fileName << "' no se puede abrir." << std::endl;
    }

    std::cout << "Escriba el nombre, la edad y el deporte." << std::endl
              << "Escriba fin de archivo para terminar la entrada." << std::endl
              << "> ";
    while(std::cin >> name >> age >> sport) {
        myFile << name << ' ' << age << ' ' << sport << std::endl;
        std::cout << "> ";
    }
    myFile.close();
    return 0;
}