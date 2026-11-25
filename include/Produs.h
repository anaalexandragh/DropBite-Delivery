#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

class Produs {
private:
    std:: string nume; 
    double pret;
    int gramaj;

public:
    Produs(const std::string& nume, double pret, int gramaj);       //constructor de initializare
    
    const std::string& getNume() const;      //getter for nume
    double getPret() const;                  //getter for pret
    int getGramaj() const;                   //getter for gramaj

    void aplicaReducere(double procent); //aplica reducere la pret

    friend std::ostream& operator<<(std::ostream& out, const Produs& produs); //operator de afisare

};

#endif