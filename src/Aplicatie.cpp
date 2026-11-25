#include "Aplicatie.h"

    Aplicatie::Aplicatie() : esteDeschisa(false) {}         //initializare constructor 

    void Aplicatie::deschide() {
        esteDeschisa = true;
        std::cout << ">>> Aplicatia DropBite a fost DESCHISA cu succes!\n\n";
    }

    void Aplicatie::inchide() {
        esteDeschisa = false;
        std::cout << "\n>>> Aplicatia DropBite a fost INCHISA.\n";
    }

    bool Aplicatie::isDeschisa() const {
        return esteDeschisa;
    }

    std::ostream& operator<<(std::ostream& out, const Aplicatie& app) {
        out << "Status Aplicatie: " << (app.esteDeschisa ? "Deschisa (Online)" : "Inchisa (Offline)");
        return out;
    }
