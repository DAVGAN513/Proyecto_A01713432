#ifndef Mago_h
#define Mago_h
#include "Combatiente.hpp"
#include <iostream>
using namespace std;

class Mago: public Combatiente{
    private:
        int mana;
    public:
        Mago();
        Mago(int vida, int salud, int ataque, int nivel, int mana);
        Mago(const Mago& o);

        //getter
        int getMana() const;

        //setter
        void setMana(int m);

        void imprimir() const override;
        void recibeAtaque(int ptosAtaque) override;
        void atacar(Combatiente& objetivo) override;
        bool estaVivo() const override;
};
#endif