#include "Arquero.hpp"
#include <iostream>
using namespace std;

Arquero::Arquero()
    :Combatiente(),precision(50){}
Arquero::Arquero(int vida, int salud, int ataque, int nivel, int precision)
    :Combatiente(vida, salud, ataque, nivel),precision(precision){}
Arquero::Arquero(const Arquero& o)
    :Combatiente(o),precision(o.precision){}

//getters
int Arquero::getPrecision() const{
    return precision;
}

//setters
void Arquero::setPrecision(int p){
    if (p < 0){
        p = 0;
    }
    if (p > 100){
        p = 100;
    }
    precision = p;
}

void Arquero::imprimir() const{
    cout <<"====ARQUERO===="<<endl;
    Combatiente::imprimir();
    cout <<"Precision de tu arquero: " <<precision<<endl;
}

void Arquero::recibeAtaque(int ptosAtaque){
    Combatiente::recibeAtaque(ptosAtaque);
}

void Arquero::atacar(Combatiente& objetivo){
    int daño = getAtaque();
    if (precision >= 70){
        daño *=2;
        cout <<"Tu golpe tu una buena precision, hizo un daño critico de: "<<daño<<endl;
    }else{
        cout <<"Tu ataque fue normal, hiciste un daño de: "<<daño<<endl;

    }
    objetivo.recibeAtaque(daño);
}