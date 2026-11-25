    #ifndef COMANDA_H
    #define COMANDA_H

    #include <vector>
    #include <iostream>
    #include "Produs.h"
    #include "Client.h"
    #include "Curier.h"

    class Comanda {
    private:                             //atributele private
        int idComanda;           
        Client client;
        Curier curier;
        std::vector<Produs> produse;
        double taxaLivrare;
        double discount;

    public:
        Comanda(int id, const Client& client, const Curier& curier, double taxaLivrare = 10.0);  //constructor de initializare
       
        Comanda(const Comanda& other); //constructor de copiere

        Comanda& operator=(const Comanda& other); //operator de copiere

        
        ~Comanda();  //destructor

        //functii
        void adaugaProdus(const Produs& produs);   
        void aplicaVoucher(double valoareDiscount);
        double calculeazaTotal() const;

        friend std::ostream& operator<<(std::ostream& out, const Comanda& comanda);
    };

    #endif