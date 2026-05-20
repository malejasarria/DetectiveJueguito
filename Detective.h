#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "Nodo.h"

#include <string>

using namespace std;

class Detective {

private:

    string nombre;

    int puntaje;

    Nodo* posicionActual;

public:

    Detective(string nom);

    void setPosicion(Nodo* nodo);

    Nodo* getPosicion();

    string getNombre();

    int getPuntaje();

    void aumentarPuntaje();

    void moverArriba();

    void moverAbajo();

    void moverIzquierda();

    void moverDerecha();

};

#endif