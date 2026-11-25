#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
private:                                     //atributele private
    std::string nume;
    std::string email;
    std::string adresa;
    std::string telefon;


public:
    //constructor de initializare pt clasa Client
    Client(const std::string& nume, const std::string& email, const std::string& adresa, const std::string& telefon);
    
    const std::string& getNume() const;      //getter nume
    const std::string& getEmail() const;     //getter email
    const std::string& getAdresa() const;    //getter adresa
    const std::string& getTelefon() const;   //getter telefon 
    
    void actualizeazaAdresa(const std::string& nouaAdresa); // functie-actualizeaza adresa   

    friend std::ostream& operator<<(std::ostream& out, const Client& client); //operator de afisare 

};

#endif