    #include "Comanda.h"

    Comanda::Comanda(int id, const Client& client, const Curier& curier, double taxaLivrare)
        : idComanda(id), client(client), curier(curier), taxaLivrare(taxaLivrare), discount(0.0) {
    }

    
    Comanda::Comanda(const Comanda& other)// Constructorul de copiere
        : idComanda(other.idComanda),
          client(other.client),
          curier(other.curier),
          produse(other.produse),
          taxaLivrare(other.taxaLivrare),
          discount(other.discount) {
    }

    
    Comanda& Comanda::operator=(const Comanda& other) {  // Operatorul de atribuire prin copiere (operator=)
        if (this != &other) {
            idComanda = other.idComanda;
            client = other.client;
            curier = other.curier;
            produse = other.produse;
            taxaLivrare = other.taxaLivrare;
            discount = other.discount;
        }
        return *this;
    }

    
    Comanda::~Comanda() {// Destructorul
      
    }

    //Functiile
    void Comanda::adaugaProdus(const Produs& produs) {
        produse.push_back(produs);
    }

    void Comanda::aplicaVoucher(double valoareDiscount) {
        if (valoareDiscount > 0.0) {
            discount = valoareDiscount;
        }
    }

    double Comanda::calculeazaTotal() const {
        double totalProduse = 0.0;
        for (const auto& p : produse) {
            totalProduse += p.getPret();
        }
        double total = totalProduse + taxaLivrare - discount;
        return (total > 0.0) ? total : 0.0; // totalul nu poate fi negativ
    }

    std::ostream& operator<<(std::ostream& out, const Comanda& comanda) {
        out << "========================================\n"
            << "COMANDA #" << comanda.idComanda << "\n"
            << "----------------------------------------\n"
            << comanda.client << "\n"     // Apeleaza operator<< din Client
            << comanda.curier << "\n"   // Apeleaza operator<< din Curier
            << "Produse comandate:\n";

        if (comanda.produse.empty()) {
            out << "  (Niciun produs adaugat)\n";
        } else {
            for (const auto& p : comanda.produse) {
                out << "  * " << p << "\n"; // Apeleaza operator<< din Produs
            }
        }

        out << "Taxa livrare: " << comanda.taxaLivrare << " RON\n"
            << "Discount aplicat: " << comanda.discount << " RON\n"
            << "TOTAL DE PLATA: " << comanda.calculeazaTotal() << " RON\n"
            << "========================================";
        return out;
    }