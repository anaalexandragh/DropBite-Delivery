#include "Produs.h"

Produs::Produs(const std::string& nume, double pret, int gramaj)
    : nume(nume), pret(pret), gramaj(gramaj) {}

const std::string& Produs::getNume() const {
    return nume;
}

double Produs::getPret() const {
    return pret;
}

int Produs::getGramaj() const {
    return gramaj;
}

void Produs::aplicaReducere(double procent) {
    if(procent > 0.0 && procent < 100.0) {
        pret -= pret * procent / 100;
    }
}

    std::ostream& operator<<(std::ostream& out, const Produs& produs) {
        out << produs.getNume() << " (" << produs.getGramaj() << "g) - " << produs.getPret() << " RON";
        return out;
}