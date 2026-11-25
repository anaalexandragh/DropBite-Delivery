#include <iostream>
#include <fstream>
#include <json.hpp>
#include "Aplicatie.h"
#include "Client.h"
#include "Produs.h"
#include "Curier.h"
#include "Comanda.h"

using nlohmann::json;

int main() {
    Aplicatie app;
    app.deschide();
    std::cout << app << "\n\n";

    if (app.isDeschisa()){
    std::cout << "DROPBITE DELIVERY PLATFORM \n\n";

    //Citire date din fisiere json
    std::ifstream fisierProduse("Date/produse.json");
    if (!fisierProduse.is_open()) {
        std::cerr << "Eroare la deschiderea Date/produse.json!\n";
        return 1;
    }
    json produseJson;
    fisierProduse >> produseJson;

    std::ifstream fisierClienti("Date/clienti.json");
    if (!fisierClienti.is_open()) {
        std::cerr << "Eroare la deschiderea Date/clienti.json!\n";
        return 1;
    }
    json clientiJson;
    fisierClienti >> clientiJson;

    std::ifstream fisierCurieri("Date/curieri.json");
    if (!fisierCurieri.is_open()) {
        std::cerr << "Eroare la deschiderea Date/curieri.json!\n";
        return 1;
    }
    json curieriJson;
    fisierCurieri >> curieriJson;

    //Creare produse din datele incarcate in fiserul json cu produse
    Produs pizza(produseJson[0]["nume"], produseJson[0]["pret"], produseJson[0]["gramaj"]);
    Produs paste(produseJson[1]["nume"], produseJson[1]["pret"], produseJson[1]["gramaj"]);
    Produs burger(produseJson[2]["nume"], produseJson[2]["pret"], produseJson[2]["gramaj"]);
    Produs desert(produseJson[3]["nume"], produseJson[3]["pret"], produseJson[3]["gramaj"]);

    //Reduceri:
    pizza.aplicaReducere(10.0); // 10% reducere

    //Clienti:
    //Creare client din primul element din fisier
    Client client1(clientiJson[0]["nume"], clientiJson[0]["email"], clientiJson[0]["adresa"], clientiJson[0]["telefon"]);
    std::cout << "Primul client: " << client1 << "\n";
    client1.actualizeazaAdresa("Str. Academiei 14, Et. 2");

    //Curieri:
    //Creare curier din primul element din fisier
    Curier curier1(curieriJson[0]["nume"], curieriJson[0]["vehicul"], curieriJson[0]["disponibil"]);
    if (curier1.isDisponibil()) {
        curier1.setDisponibil(false); // Curierul preia comanda si devine ocupat
    }


    //Comenzi:
    //Creare comanda si adaugare produse
    Comanda comanda1(1, client1, curier1, 10.0);
    comanda1.adaugaProdus(pizza);
    comanda1.adaugaProdus(burger);
    comanda1.adaugaProdus(paste);
    comanda1.adaugaProdus(desert);
    comanda1.aplicaVoucher(15.0); // 15 lei reducere

    //Afisare comanda(compunere de apeluri operator<<)
    std::cout << comanda1 << "\n\n";

    //Testare Constructor de Copiere
    std::cout << ">>> Test: Constructor de Copiere (Comanda copie = comanda1)\n";
    Comanda comandaCopie = comanda1;
    std::cout << "Copie creata cu succes. Total copie: " << comandaCopie.calculeazaTotal() << " RON\n\n";

    //Testare Operator de Atribuire
    std::cout << ">>> Test: Operator de Atribuire (comandaAlta = comanda1)\n";
    Client client2(clientiJson[1]["nume"], clientiJson[1]["email"], clientiJson[1]["adresa"], clientiJson[1]["telefon"]);
    Curier curier2(curieriJson[1]["nume"], curieriJson[1]["vehicul"], curieriJson[1]["disponibil"]);
    Comanda comandaAlta(923, client2, curier2, 5.0);

    comandaAlta = comanda1; // Atribuire comanda1 peste comandaAlta
    std::cout << "Atribuire reusita. Total comanda atribuita: " << comandaAlta.calculeazaTotal() << " RON\n\n";

    //Estimari timp livrari:
    double distanta = 4.5; 
    std::cout << "Curierul " << curier1.getNume() << " livreaza cu " << curier1.getVehicul()
              << " si estimeaza livrarea la: " << curier1.estimeazaTimpLivrare(distanta) << " minute.\n";

    //Livrarea comenzii
     curier1.finalizeazaLivrare();
    std::cout << "Status curier dupa livrare: " << curier1 << "\n";
    std::cout << "Comenzi livrate in total: " << curier1.getComenziLivrate() << "\n";
    }

    app.inchide();
    std::cout << app << "\n";
    return 0;
}
