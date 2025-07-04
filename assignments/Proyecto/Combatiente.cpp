//GEnera la implementación de la clase base Personaje
#include "Combatiente.hpp"
#include <iostream>
using namespace std;

//constructores
Combatiente::Combatiente()
    :vida(100),salud(100),ataque(20),nivel(1){}
Combatiente::Combatiente(int v, int s, int a, int n)
    :vida(v), salud(s), ataque(a), nivel(n){}
Combatiente::Combatiente(const Combatiente& o)
    :vida(o.vida), salud(o.salud), ataque(o.ataque), nivel(o.nivel){}

//getters
int Combatiente::getVida()const{
    return vida;
}
int Combatiente::getSalud()const{
    return salud;
}
int Combatiente::getAtaque()const{
    return ataque;
}
int Combatiente::getNivel()const{
    return nivel;
}

//setters
void Combatiente::setVida(int v){
    vida = v;
    if (vida > salud){
        salud = vida;
    }
}
void Combatiente::setSalud(int s){
    salud = s;
    if (salud > vida){
        salud = vida;
    }else if (salud < 0){
        salud = 0;
    }
}
void Combatiente::setAtaque(int a){
    ataque = a;
}
void Combatiente::setNivel(int n){
    nivel = n;
}

int Combatiente::porcentajeSalud()const{
    if (vida == 0){
        return 0;
    }
    int porcentaje = (salud * 100) / vida;
    
    if(porcentaje > 100){
        porcentaje = 100;
    }
    return porcentaje;
}


void Combatiente::imprimeBarra()const{
    int barra = 20;
    int porcentaje = porcentajeSalud();
    int cantsalud = (porcentaje * barra)/100;
    int cantperdida = barra - cantsalud;

    for (int i = 0; i < cantsalud; ++i){
        std::cout << "%";
    }
    for (int i = 0; i < cantperdida; ++i) {
        std::cout << "=";
    }
    std::cout << " (" << porcentaje << "%)" << std::endl;
}

void Combatiente::recibeAtaque(int ptosAtaque){
    salud -= ptosAtaque;
    if (salud > vida){
        salud = vida;
    }else if (salud < 0){
        salud = 0;
    }
}

void Combatiente::atacar(Combatiente& objetivo){
    int daño = ataque/2;
    cout << "Hace un daño de: " << daño;
    objetivo.recibeAtaque(daño);
}

void Combatiente::imprimir()const{
    cout << "Nivel: " <<nivel <<endl;
    cout << "Tu vida es de: " <<vida <<endl;
    cout << "Cuida tu salud, es de: " <<salud <<endl;
    cout << "Tu ataque es de: " <<ataque <<endl;
    imprimeBarra(); 
}