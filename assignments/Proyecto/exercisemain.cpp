#include "Combatiente.hpp"
#include <iostream>
using namespace std;

int main(){
    Combatiente personaje (100,100,15,3);
    Combatiente enemigo (100,100,20,2);

    cout <<"Valores iniciales: ";
    personaje.imprimir();
    enemigo.imprimir();

    cout <<"Tu personaje ataca al enemigo: ";
    personaje.atacar(enemigo);

    cout <<"Condicion despues de tu ataque es de: ";
    personaje.imprimir();
    enemigo.imprimir();

    cout <<"Enemigo te ataca: ";
    enemigo.atacar(personaje);

    cout <<"Condicion despues de tu ataque es de: ";
    personaje.imprimir();
    enemigo.imprimir();
    return 0;
}
