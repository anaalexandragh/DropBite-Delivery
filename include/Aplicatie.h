#ifndef APLICATIE_H
#define APLICATIE_H

#include <iostream>

class Aplicatie {
    private:
        bool esteDeschisa;     

    public:
        Aplicatie(); //constructor de initializare ca inchisa

        void deschide();
        void inchide();
        bool isDeschisa() const;  //const- nu modifica atribut al clasei

        //operator<< pentru afișarea statusului, friend- pt a putea accesa atributul privat "esteDeschisa"
        friend std::ostream& operator<<(std::ostream& out, const Aplicatie& app);
    };

    #endif