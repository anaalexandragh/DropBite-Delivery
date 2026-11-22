#include "Client.h"

Client::Client(const std::string& nume, const std::string& email, const std::string& adresa, const std::string& telefon)
    : nume(nume), email(email), adresa(adresa), telefon(telefon) {}

const std::string& Client::getNume() const {
    return nume;
}

const std::string& Client::getEmail() const {
    return email;
}

const std::string& Client::getAdresa() const {
    return adresa;
}

const std::string& Client::getTelefon() const {
    return telefon;
}

void Client::actualizeazaAdresa(const std::string& nouaAdresa) {
    adresa = nouaAdresa;
}

   std::ostream& operator<<(std::ostream& out, const Client& client) {
        out << "Client: " << client.getNume() << " (" << client.getEmail()
            << "), Adresa: " << client.getAdresa()
            << ", Tel: " << client.getTelefon();
        return out;
}

