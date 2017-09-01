#include <iostream>
#include <fstream>

#include "client.hpp"

int main()
{
    std::string filename = "Credito.txt";
    std::ofstream creditOut(filename, std::ios::binary);
    if(!creditOut) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        std::exit(1);
    }

    Client client;
    for(int i = 0; i < 100; ++i) {
        creditOut.write(reinterpret_cast<const char *>(&client), sizeof(Client));
    }

    return 0;
}

