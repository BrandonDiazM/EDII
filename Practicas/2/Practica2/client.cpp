/*
Equipo 4
- De Santiago Macías, Sergio Miguel
- Díaz Flores, Brandon
- González Gómez, Sebastián
- Hernández Orozco, Kenneth Michel
- Zúñiga Castellano, Francisco Jesús
*/

#include "client.hpp"

Client::Client()
{
    this->accountNumber = 0;
    this->name[10] = {0};
    this->lastName[15] = {0};
    this->balance = 0.0;
}

Client::Client(const int accountNumber, const std::string name, const std::string lastName, const double balance)
{
    this->accountNumber = accountNumber;
    std::strncpy(this->name, name.c_str(), sizeof(this->name));
    this->name[sizeof(this->name) - 1] = 0;
    std::strncpy(this->lastName, lastName.c_str(), sizeof(this->lastName));
    this->lastName[sizeof(this->lastName) - 1] = 0;
    this->balance = balance;
}

void Client::setAccountNumber(const int accountNumber)
{
    this->accountNumber = accountNumber;
}

void Client::setName(const std::string name)
{
    std::strncpy(this->name, name.c_str(), sizeof(this->name));
    this->name[sizeof(this->name) - 1] = 0;
}

void Client::setLastName(const std::string lastName)
{
    std::strncpy(this->lastName, lastName.c_str(), sizeof(this->lastName));
    this->lastName[sizeof(this->lastName) - 1] = 0;
}

void Client::setBalance(const double balance)
{
    this->balance = balance;
}

int Client::getAccountNumber()
{
    return this->accountNumber;
}

std::string Client::getName()
{
    return this->name;
}

std::string Client::getLastName()
{
    return this->lastName;
}

double Client::getBalance()
{
    return this->balance;
}

