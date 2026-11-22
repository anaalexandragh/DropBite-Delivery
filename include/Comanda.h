    #ifndef COMANDA_H
    #define COMANDA_H

    #include <vector>
    #include <iostream>
    #include "Produs.h"
    #include "Client.h"
    #include "Curier.h"

    class Comanda {
    private:
        int idComanda;
        Client client;
        Curier curier;
        std::vector<Produs> produse;
        double taxaLivrare;
        double discount;

    public:
        Comanda(int id, const Client& client, const Curier& curier, double taxaLivrare = 10.0);
       
        Comanda(const Comanda& other); // Constructor de copiere

        Comanda& operator=(const Comanda& other); //Operator de atribuire

        ~Comanda();  // Destructor

        //functii
        void adaugaProdus(const Produs& produs);   
        void aplicaVoucher(double valoareDiscount);
        double calculeazaTotal() const;

        friend std::ostream& operator<<(std::ostream& out, const Comanda& comanda);
    };

    #endif