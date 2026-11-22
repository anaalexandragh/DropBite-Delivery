#include <iostream>
#include "Produs.h"
#include "Client.h"
#include "Curier.h"
#include "Comanda.h"

int main() {
    std::cout << "=== DROPBITE DELIVERY PLATFORM ===\n\n";

   
    Produs pizza("Pizza Margherita", 38.0, 450); // produsele din meniu
    Produs burger("Burger Vita Angus", 42.0, 350);
    Produs limonada("Limonada cu Menta", 14.0, 500);

  
    pizza.aplicaReducere(10.0); // 10% reducere

    
    Client client1("Ana Maria", "ana@email.com", "Str. Academiei 14", "0712345678");// clientul

    
    Curier curier1("Mihai Ionescu", "scuter");//curierul

    
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
    std::cout << "Curierul " << curier1.getNume() << " estimeaza livrarea la: "
              << curier1.estimeazaTimpLivrare(distanta) << " minute.\n";

    curier1.finalizeazaLivrare();
    std::cout << "Status curier dupa livrare: " << curier1 << "\n";

    return 0;
}
