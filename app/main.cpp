#include <iostream>
#include <json.hpp>
#include "Client.h"
#include "Produs.h"
#include "Curier.h"
#include "Comanda.h"

using nlohmann::json;

int main() {
    std::cout << "=== DROPBITE DELIVERY PLATFORM ===\n\n";

   
    Produs pizza("Pizza Margherita", 38.0, 450); // produsele din meniu
    Produs burger("Burger Vita Angus", 42.0, 350);
    Produs limonada("Limonada cu Menta", 14.0, 500);

  
    pizza.aplicaReducere(10.0); // 10% reducere

    // json j = json::parse(R"({"happy": true})");
    // std::cout << "JSON test: " << j.dump() << "\n";
    
    // Clientul
    // Client client1("Ana Maria", "ana@email.com", "Str. Academiei 14", "0712345678");
    FILE *clienti = fopen("Date/clienti.json", "r");
    std::string jsonContent;
    if (clienti) {
        char buffer[256];
        
        while (fgets(buffer, sizeof(buffer), clienti)) {
            jsonContent += buffer;
        }
        fclose(clienti);
    }
    json clientJson = json::parse(jsonContent);
        std::string nume = clientJson["nume"];
        std::string email = clientJson["email"];
        std::string adresa = clientJson["adresa"];
        std::string telefon = clientJson["telefon"];

    Client client1(nume, email, adresa, telefon);
    std::cout << "Client creat cu succes: " << client1 << "\n";

    client1.actualizeazaAdresa("Str. Academiei 14, Et. 2");

    // Curierul
    Curier curier1("Mihai Ionescu", "scuter");
    if (curier1.isDisponibil()) {
        curier1.setDisponibil(false); // Curierul preia comanda si devine ocupat
    }

    
    Comanda comanda1(101, client1, curier1, 10.0); // taxa livrare: 10 lei     // Comanda 
    comanda1.adaugaProdus(pizza);
    comanda1.adaugaProdus(burger);
    comanda1.adaugaProdus(limonada);

    comanda1.aplicaVoucher(15.0); // 15 lei reducere

    
    std::cout << comanda1 << "\n\n";// Afisare comanda (compunere de apeluri operator<<)

    
    std::cout << ">>> Test: Constructor de Copiere (Comanda copie = comanda1)\n";// constructor de copiere si operator de atribuire
    Comanda comandaCopie = comanda1;
    std::cout << "Copie creata cu succes. Total copie: " << comandaCopie.calculeazaTotal() << " RON\n\n";

    std::cout << ">>> Test: Operator de Atribuire (comandaAlta = comanda1)\n";
    Client client2("George Popa", "george@email.com", "Str. Lipscani 10", "0799999999");
    Curier curier2("Dan Vasile", "bicicleta");
    Comanda comandaAlta(999, client2, curier2, 5.0);


    
    comandaAlta = comanda1;                   //Atribuire comanda1 peste comandaAlta
    std::cout << "Atribuire reusita. Total comanda atribuita: " << comandaAlta.calculeazaTotal() << " RON\n\n";

    
    double distanta = 4.5; // km              //Estimare timp si finalizare livrare
    std::cout << "Curierul " << curier1.getNume() << " livreaza cu " << curier1.getVehicul()
              << " si estimeaza livrarea la: " << curier1.estimeazaTimpLivrare(distanta) << " minute.\n";

    curier1.finalizeazaLivrare();
    std::cout << "Status curier dupa livrare: " << curier1 << "\n";
    std::cout << "Comenzi livrate in total: " << curier1.getComenziLivrate() << "\n";

    FILE *file = fopen("date.txt", "r");
    if (file) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            std::cout << buffer;
        }
        fclose(file);
    } else {
        std::cerr << "Eroare la deschiderea fișierului date.txt\n";
    }

    

    return 0;
}
