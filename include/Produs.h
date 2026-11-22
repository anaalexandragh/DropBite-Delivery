#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

// What is declared here is what app/ and tests/ can reach; helpers that do not need
// to be public stay in the .cpp or in src/internal/.
class Produs {
private:
    std:: string nume; 
    double pret;
    int gramaj;

public:
    Produs(const std::string& nume, double pret, int gramaj);       //constructor
    
    const std::string& getNume() const;      //getter for nume
    double getPret() const;                  //getter for pret
    int getGramaj() const;                   //getter for gramaj

    void aplicaReducere(double procent); //aplica reducere la pret

    friend std::ostream& operator<<(std::ostream& out, const Produs& produs); //operator output

};

#endif