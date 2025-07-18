#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero()
    :Combatiente(), fuerza(20), escudo(50){}
Guerrero::Guerrero(int vida, int salud, int ataque, int nivel, int escudo, int fuerza)
    :Combatiente(vida, salud, ataque, nivel),escudo(escudo), fuerza(fuerza){}
Guerrero::Guerrero(const Guerrero& o)
    :Combatiente(o),escudo(o.escudo),fuerza(o.fuerza){}

//getters
int Guerrero::getEscudo() const{
    return escudo;
}
int Guerrero::getFuerza() const{
    return fuerza;
}

//setters
void Guerrero::setEscudo(int e){
     escudo = e;
    if (escudo < 0){
        escudo = 0;
    }
}
void Guerrero::setFuerza(int f){
    fuerza = f;
    if (fuerza < 0){
        fuerza = 0;
    }
}

void Guerrero::imprimir() const{
    cout <<"====GUERRERO===="<<endl;
    Combatiente::imprimir();
    cout <<"Escudo: " <<escudo<<endl;
    cout <<"Fuerza: " <<fuerza<<endl;
}

void Guerrero::recibeAtaque(int ptosAtaque){
    int atac = fuerza/2;
    int dañoreal = ptosAtaque - atac;
    if (dañoreal < 0){
        dañoreal = 0;
    }
    if (escudo > 0){
        if (escudo >= dañoreal){
            escudo -=dañoreal;
            cout <<"El escudo absorbio el golpe del enemigo, tu escudo tiene una vida de: "<<escudo<<endl;
        }else{
            int dañorestante = dañoreal - escudo;
            escudo = 0;
            cout <<"El escudo quedo destruido, tu daño restante es de: "<<dañorestante<<endl;
            Combatiente::recibeAtaque(dañorestante);
        }
    }else{
        Combatiente::recibeAtaque(dañoreal);
    }
}
void Guerrero::atacar(Combatiente& objetivo){
    int daño = getAtaque() + (fuerza/2);
    cout <<"El guerro ataco con una fuerza de: "<<daño<<endl;
    objetivo.recibeAtaque(daño);
}
bool Guerrero::estaVivo() const {
    return getSalud() > 0 || escudo > 0;
    if (!estaVivo()) {
    cout << "El guerrero ha caído en batalla." << endl;
    }

}
