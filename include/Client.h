#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
private:
    std::string nume;
    std::string email;
    std::string adresa;
    std::string telefon;


public:
    Client(const std::string& nume, const std::string& email, const std::string& adresa, const std::string& telefon);       //constructor
    
    const std::string& getNume() const;      //getter for nume
    const std::string& getEmail() const;     //getter for email
    const std::string& getAdresa() const;    //getter for adresa
    const std::string& getTelefon() const;   //getter for telefon 
    
    void actualizeazaAdresa(const std::string& nouaAdresa); //actualizeaza adresa   

    friend std::ostream& operator<<(std::ostream& out, const Client& client); //operator output

};

#endif