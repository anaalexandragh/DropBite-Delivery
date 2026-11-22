#include <iostream>
#include <array>
#include "Produs.h"

int main() {
    Produs pizza("Pizza Margherita", 35.0, 450);
    std::cout << "Inainte de reducere: " << pizza << "\n";

    pizza.aplicaReducere(10.0); // 10% reducere
    std::cout << "Dupa reducere (10%): " << pizza << "\n";
    return 0;
}
