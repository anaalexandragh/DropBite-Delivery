   #ifndef CURIER_H
    #define CURIER_H

    #include <string>
    #include <iostream>

    class Curier {
    private:
        std::string nume;
        std::string vehicul;
        bool disponibil;
        int comenziLivrate;

    public:
        Curier(const std::string& nume, const std::string& vehicul, bool disponibil = true); //constructor de initializare

        const std::string& getNume() const;          //getter for nume
        const std::string& getVehicul() const;         //getter for vehicul
        bool isDisponibil() const;                     //getter for disponibil
        int getComenziLivrate() const;                   //getter for comenziLivrate

        void setDisponibil(bool stare);     //setter--modifica atributul disponibil
        void finalizeazaLivrare();
        int estimeazaTimpLivrare(double distantaKm) const;

        friend std::ostream& operator<<(std::ostream& out, const Curier& curier);
    };

    #endif 