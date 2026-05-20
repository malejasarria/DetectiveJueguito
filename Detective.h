#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "Nodo.h"
#include "Pista.h"
#include "Testigo.h"

#include <string>
#include <stack>
#include <queue>

using namespace std;

class Detective {

private:

    string nombre;

    int puntaje;

    Nodo* posicionActual;

    stack<Pista> pistas;

    queue<Testigo> testigos;

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

    void agregarPista(Pista pista);

    void mostrarPistas();

    void revisarPista();

    void agregarTestigo(Testigo testigo);

    void interrogarTestigo();

};

#endif