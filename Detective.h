#ifndef DETECTIVE_H
#define DETECTIVE_H

#include "Nodo.h"
#include "PilaPistas.h"
#include "ColaTestigos.h"
#include "HashSospechosos.h"
#include "Testigo.h"
#include "Sospechoso.h"

#include <string>

using namespace std;

class Detective {

private:

    string nombre;

    int puntaje;

    Nodo* posicionActual;

    PilaPistas pistas;

    ColaTestigos testigos;

    HashSospechosos sospechosos;

    Sospechoso culpableReal;

    bool cabelloDescubierto;

    bool pielDescubierta;

    bool sexoDescubierto;

    bool estaturaDescubierta;

public:

    Detective(string nom);

    void setPosicion(
            Nodo* nodo);

    Nodo* getPosicion();

    string getNombre() const;

    int getPuntaje() const;

    void aumentarPuntaje();

    void setPuntaje(
            int p);

    void moverArriba();

    void moverAbajo();

    void moverIzquierda();

    void moverDerecha();

    void agregarPista(
            char tipo);

    void mostrarPistas();

    void revisarPista();

    char usarPista();

    void agregarTestigo(
            Testigo testigo);

    void interrogarTestigo();

    void agregarSospechoso(
            Sospechoso sospechoso);

    void mostrarSospechosos();

    void setCulpable(
            Sospechoso sospechoso);

    Sospechoso getCulpable() const;

    int cantidadPistas();

    bool acusar(
            string nombre);
};

#endif