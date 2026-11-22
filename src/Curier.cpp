    #include "Curier.h"

    Curier::Curier(const std::string& nume, const std::string& vehicul, bool disponibil)
        : nume(nume), vehicul(vehicul), disponibil(disponibil), comenziLivrate(0) {
    }

    const std::string& Curier::getNume() const {
        return nume;
    }

    const std::string& Curier::getVehicul() const {
        return vehicul;
    }

    bool Curier::isDisponibil() const {
        return disponibil;
    }

    int Curier::getComenziLivrate() const {
        return comenziLivrate;
    }

    void Curier::setDisponibil(bool stare) {      //setter
        disponibil = stare;
    }

    void Curier::finalizeazaLivrare() {
        comenziLivrate++;
        disponibil = true; // dupa livrare devine din nou liber
    }

    int Curier::estimeazaTimpLivrare(double distantaKm) const {
        int minutePerKm = 5; 

        if (vehicul == "scuter") {
            minutePerKm = 3;
        } else if (vehicul == "masina") {
            minutePerKm = 4;
        } else if (vehicul == "bicicleta") {
            minutePerKm = 6;
        }

        return static_cast<int>(distantaKm * minutePerKm);    //rotunjesc timpul de livrare la cel mai apropiat intreg
    }

    std::ostream& operator<<(std::ostream& out, const Curier& curier) {
        out << "Curier: " << curier.nume << " [" << curier.vehicul << "]"
            << " - Status: " << (curier.disponibil ? "Disponibil" : "Ocupat")
            << " (Livrari: " << curier.comenziLivrate << ")";
        return out;
    }