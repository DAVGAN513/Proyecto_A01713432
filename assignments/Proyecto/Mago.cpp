#include "Mago.hpp"
#include <iostream>
using namespace std;

Mago::Mago()
    :Combatiente(),mana(100){}
Mago::Mago(int vida, int salud, int ataque, int nivel, int mana)
    :Combatiente(vida, salud, ataque, nivel), mana(mana){}
Mago::Mago(const Mago& o)
    :Combatiente(o),mana(o.mana){}

int Mago::getMana() const{
    return mana;
}

void Mago::imprimir() const{
    cout <<"====MAGO===="<<endl;
    Combatiente::imprimir();
    cout <<"Tu mago tiene una mana de: " <<mana<<endl;
}

void Mago::recibeAtaque(int ptosAtaque){
    int dañorecibido = ptosAtaque;
    int nivel = getNivel();
    if (nivel >= 4 and mana >=80){
        dañorecibido = ptosAtaque/3;
    }else if (nivel >= 3 and nivel < 4 and mana >= 85){
        dañorecibido = ptosAtaque/2;
    }else if (nivel <= 2 and mana == 100){
        dañorecibido = (ptosAtaque * 3) / 4;
    }
    Combatiente::recibeAtaque(dañorecibido);
}

void Mago::atacar(Combatiente& objetivo){
    int baseataque = getAtaque();
    int daño = baseataque;

    if (mana >=80){
        daño = baseataque * 2;
        mana -=30;
        cout <<"Tu golpe fue PODEROSO, hiciste un daño de: "<<daño<<endl;
        cout <<"Te quedo una mana de: "<<mana<<endl;
    }else if (mana >= 50){
        daño = baseataque + (baseataque/2);
        mana -= 15;
        cout <<"Tu golpe tuvo potencia, hiciste un daño de: "<<daño<<endl;
        cout <<"Te quedo una mana de: "<<mana<<endl;
    }else if (mana < 50){
        daño = baseataque;
        mana -= 10;
        cout <<"Tu golpe fue normal, hiciste un daño de: "<<daño<<endl;
        cout <<"Te quedo una mana de: "<<mana<<endl;
    }
    if (mana < 0){
        mana = 0;
    }
    objetivo.recibeAtaque(daño);
}