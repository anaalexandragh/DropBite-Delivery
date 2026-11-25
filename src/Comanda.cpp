    #include "Comanda.h"

    //constructor de initializare cu parametrii
    Comanda::Comanda(int id, const Client& client, const Curier& curier, double taxaLivrare)
        : idComanda(id), client(client), curier(curier), taxaLivrare(taxaLivrare), discount(0.0) {
    }


    // Constructorul de copiere --obiect nou
    Comanda::Comanda(const Comanda& other)
        : idComanda(other.idComanda),      //lista de initializare a constuctorului de copiere
          client(other.client),              //copiez atributul din obiectul sursă "other" în noul atribut
          curier(other.curier),
          produse(other.produse),
          taxaLivrare(other.taxaLivrare),
          discount(other.discount) {
    }


     // Operatorul de atribuire prin copiere (operator=) --copiez datele peste alt obiect
    Comanda& Comanda::operator=(const Comanda& other) { 
        if (this != &other) {                                    //ma asigur ca nu auto-atribui c1=c1
            idComanda = other.idComanda;
            client = other.client;
            curier = other.curier;
            produse = other.produse;
            taxaLivrare = other.taxaLivrare;
            discount = other.discount;
        }
        return *this;                                //dereferentiez, returnez obiectul curent
    }

    
    Comanda::~Comanda() {// Destructorul, elibereaza memoria, apeleaza pe rand 
      //desstructorii din produse(std::vector), curier, client
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
        double total = totalProduse + taxaLivrare - discount;           //calcul de achitat total
        return (total > 0.0) ? total : 0.0;                 // totalul nu poate fi negativ
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
                out << "  * " << p << "\n";           // Apeleaza operator<< din Produs
            }
        }

        out << "Taxa livrare: " << comanda.taxaLivrare << " RON\n"
            << "Discount aplicat: " << comanda.discount << " RON\n"
            << "TOTAL DE PLATA: " << comanda.calculeazaTotal() << " RON\n"
            << "========================================";
        return out;
    }