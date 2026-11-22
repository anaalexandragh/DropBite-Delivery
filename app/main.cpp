#include <iostream>
#include <array>
#include "Produs.h"
#include "Client.h"

int main() {
    Produs pizza("Pizza Margherita", 35.0, 450);
    std::cout << "Inainte de reducere: " << pizza << "\n";

    pizza.aplicaReducere(10.0); // 10% reducere
    std::cout << "Dupa reducere (10%): " << pizza << "\n";

    std::cout << "\n--- Test Client ---\n";
    Client client1("Ana Maria", "ana@email.com", "Str. Academiei 14", "0712345678");
    std::cout << client1 << "\n";

    client1.actualizeazaAdresa("Bd. Regina Elisabeta 4");
    std::cout << "Dupa mutare: " << client1 << "\n";

    return 0;
}
