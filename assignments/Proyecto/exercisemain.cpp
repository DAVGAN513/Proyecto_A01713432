#include "Combatiente.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
using namespace std;

int main(){
    Guerrero guerrero (100,100,15,3,75,25);
    Arquero arquero (100,100,20,2,80);
    Mago mago (120,120,25,3,85);


    cout <<"Valores iniciales: ";
    guerrero.imprimir();
    arquero.imprimir();
    mago.imprimir();

    cout <<"Guerrero ataca al Arquero: ";
    guerrero.atacar(arquero);
    arquero.imprimir();

    cout <<"Arquero ataca al Mago: ";
    arquero.atacar(mago);
    mago.imprimir();

    cout <<"Mago ataca al Guerrero: ";
    mago.atacar(guerrero);
    guerrero.imprimir();

    cout <<"Arquero ataca al Guerrero: ";
    arquero.atacar(guerrero);
    guerrero.imprimir();

    cout <<"Condicion despues de tu ataque es de: ";
    guerrero.imprimir();
    arquero.imprimir();
    mago.imprimir();
    return 0;
}
