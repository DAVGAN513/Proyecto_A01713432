// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#ifndef Combatiente_h
#define Combatiente_h
#include <iostream>
using namespace std;

class Combatiente{
    private:
        int vida;
        int salud;
        int ataque;
        int nivel;
    public:
        // Constructores
        Combatiente();
        Combatiente(int vida, int salud, int ataque, int nivel);
        Combatiente(const Combatiente& o);

        //getters
        int getVida() const;
        int getSalud() const;
        int getAtaque() const;
        int getNivel() const;

        //setters
        void setVida(int v);
        void setSalud(int s);
        void setAtaque(int a);
        void setNivel(int n);

        //metodos
        int porcentajeSalud() const;
        void imprimeBarra() const;
        virtual void recibeAtaque(int ptosAtaque);
        virtual void atacar(Combatiente& objetivo);
        virtual void imprimir() const;
};
#endif