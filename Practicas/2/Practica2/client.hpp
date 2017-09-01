#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <cstring>


class Client
{
private:
    int accountNumber;
    char name[10];
    char lastName[15];
    double balance;

public:
    Client();
    Client(const int, const std::string, const std::string, const double);

    void setAccountNumber(const int);
    void setName(const std::string);
    void setLastName(const std::string);
    void setBalance(const double);

    int getAccountNumber();
    std::string getName();
    std::string getLastName();
    double getBalance();
};

#endif // CLIENT_H
