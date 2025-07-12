#ifndef Guerrero_h
#define Guerrero_h
#include "Combatiente.hpp"
#include <iostream>
using namespace std;

class Guerrero: public  Combatiente{
    private:
        int escudo;
        int fuerza;
    public:
        Guerrero();
        Guerrero(int vida, int salud, int ataque, int nivel, int escudo, int fuerza);
        Guerrero(const Guerrero& o);
        
        //getters
        int getEscudo() const;
        int getFuerza() const;

        //setters
        void setEscudo(int e);
        void setFuerza(int f);

        //metodos
        void imprimir() const override;
        void recibeAtaque(int ptosAtaque) override;
        void atacar(Combatiente& objetivo) override;
};
#endif