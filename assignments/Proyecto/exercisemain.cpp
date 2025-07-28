#include "Combatiente.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
#include <vector>
using namespace std;

void mostrarEjercito(const vector<Combatiente*>& ejercito, const string& nombre) {
    cout << "\n===== EJÉRCITO " << nombre << " =====\n";
    for (size_t i = 0; i < ejercito.size(); ++i) {
        cout << "Combatiente: " << (i + 1) << ":\n";
        ejercito[i]->imprimir();
    }
}

void simularBatalla(vector<Combatiente*>& ejercito1, vector<Combatiente*>& ejercito2) {
    cout << "\n==== COMIENZA LA BATALLA ====\n";
    int ronda = 1;
    const int MAX_RONDAS = 20;

    while (!ejercito1.empty() && !ejercito2.empty() && ronda <= MAX_RONDAS) {
        cout << "\n===== RONDA " << ronda << " =====\n";

    try {
        Combatiente* c1 = ejercito1.front();
        Combatiente* c2 = ejercito2.front();

        c1->atacar(*c2);
        c2->atacar(*c1);

        if (!c1->estaVivo()) {
            delete c1;
            ejercito1.erase(ejercito1.begin());
        }

        if (!c2->estaVivo()) {
            delete c2;
            ejercito2.erase(ejercito2.begin());
        }

    } catch (const exception& e) {
        cerr << "Error durante la ronda: " << e.what() << endl;
        break;
    }

    ronda++;
}

    cout << "\n==== FIN DE LA BATALLA ====\n";
    if (ejercito1.empty()) {
        cout << "El Ejército 2 ha ganado la guerra \n";
        mostrarEjercito(ejercito2, "2 (GANADOR)");
    } else {
        cout << "El Ejército 1 ha ganado la guerra \n";
        mostrarEjercito(ejercito1, "1 (GANADOR)");
    }
}


int main(){
    vector<Combatiente*> ejercito1;
    vector<Combatiente*> ejercito2;

    try {
        // Ejército 1
        ejercito1.push_back(new Guerrero(100, 100, 15, 2, 50, 20));
        ejercito1.push_back(new Arquero(90, 90, 18, 1, 80));
        ejercito1.push_back(new Mago(120, 120, 25, 3, 85));
        ejercito1.push_back(new Guerrero(110, 100, 14, 1, 40, 25));
        ejercito1.push_back(new Arquero(95, 90, 20, 2, 75));

        // Ejército 2
        ejercito2.push_back(new Mago(115, 110, 20, 3, 90));
        ejercito2.push_back(new Guerrero(105, 100, 16, 2, 45, 28));
        ejercito2.push_back(new Arquero(100, 90, 17, 1, 70));
        ejercito2.push_back(new Guerrero(95, 90, 15, 1, 30, 22));
        ejercito2.push_back(new Mago(120, 110, 25, 4, 95));

        mostrarEjercito(ejercito1, "1");
        mostrarEjercito(ejercito2, "2");

        simularBatalla(ejercito1, ejercito2);

    } catch (const exception& e) {
        cout << "Se produjo una excepción: " << e.what() << endl;

        for (Combatiente* c : ejercito1) delete c;
        for (Combatiente* c : ejercito2) delete c;
    }

    return 0;
}
    
