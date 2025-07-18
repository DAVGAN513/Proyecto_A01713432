#ifndef Arquero_h
#define Arquero_h
#include "Combatiente.hpp"
#include <iostream>
using namespace std;

class Arquero: public Combatiente{
    private:
        int precision;
    public:
        Arquero();
        Arquero(int vida, int salud, int ataque, int nivel, int precision);
        Arquero(const Arquero& o);

        //getter
        int getPrecision() const;

        //setter
        void setPrecision(int p);

        void imprimir() const override;
        void recibeAtaque(int ptosAtaque) override;
        void atacar(Combatiente& objetivo) override;
        bool estaVivo() const override;

};
#endif