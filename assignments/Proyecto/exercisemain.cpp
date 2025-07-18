#include "Combatiente.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Combatiente* c1 = new Guerrero(100, 100, 15, 3, 75, 25);
    Combatiente* c2 = new Arquero(100, 100, 20, 2, 80);
    Combatiente* c3 = new Mago(120, 120, 25, 3, 85);

    vector<Combatiente*> combatientes;
    combatientes.push_back(c1);
    combatientes.push_back(c2);
    combatientes.push_back(c3);

    cout <<"=== ESTADO INICIAL DE TUS PERSONAJES ===" << endl;
    c1->imprimir();
    cout << endl;
    c2->imprimir();
    cout << endl;
    c3->imprimir();
    cout << endl;

    cout <<"=== ATAQUES DEL PRIMER COMBATIENTE ===" << endl;
    cout <<"Guerrero ataca a Arquero: " << endl;
    c1->atacar(*c2);
    cout <<"Estado del Arquero: " << endl;
    c2->imprimir();
    cout << endl;

    cout <<"Guerrero ataca a Mago: " << endl;
    c1->atacar(*c3);
    cout <<"Estado del Mago :" << endl;
    c3->imprimir();
    cout << endl;

    cout <<"Mago ataca a Arquero: " <<endl;
    c3->atacar(*c2);
    cout <<"Estado del Arquero: " <<endl;
    c2->imprimir();
    cout << endl;

    delete c1;
    delete c2;
    delete c3;
    return 0;
}
