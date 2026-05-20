#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "Nodo.h"
#include "Pista.h"
#include "Testigo.h"
#include "Sospechoso.h"

#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Detective {

private:

    string nombre;

    int puntaje;

    Nodo* posicionActual;

    stack<Pista> pistas;

    queue<Testigo> testigos;

    unordered_map<string, Sospechoso> sospechosos;

    string culpableReal;

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

    void usarPista();

    void revisarPista();

    void agregarTestigo(Testigo testigo);

    void interrogarTestigo();

    void agregarSospechoso(Sospechoso sospechoso);

    void mostrarSospechosos();

    void setCulpable(string nombre);

    string getCulpable();

    int cantidadPistas();

    bool acusar(string nombre);

};

#endif