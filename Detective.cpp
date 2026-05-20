#include "Detective.h"

Detective::Detective(string nom) {

    nombre = nom;

    puntaje = 0;

    posicionActual = nullptr;
}

void Detective::setPosicion(Nodo* nodo) {

    posicionActual = nodo;
}

Nodo* Detective::getPosicion() {

    return posicionActual;
}

string Detective::getNombre() {

    return nombre;
}

int Detective::getPuntaje() {

    return puntaje;
}

void Detective::aumentarPuntaje() {

    puntaje++;
}

void Detective::moverArriba() {

    if (posicionActual->arriba != nullptr) {

        posicionActual = posicionActual->arriba;

        aumentarPuntaje();
    }
}

void Detective::moverAbajo() {

    if (posicionActual->abajo != nullptr) {

        posicionActual = posicionActual->abajo;

        aumentarPuntaje();
    }
}

void Detective::moverIzquierda() {

    if (posicionActual->izquierda != nullptr) {

        posicionActual = posicionActual->izquierda;

        aumentarPuntaje();
    }
}

void Detective::moverDerecha() {

    if (posicionActual->derecha != nullptr) {

        posicionActual = posicionActual->derecha;

        aumentarPuntaje();
    }
}