#include "Detective.h"

#include <iostream>

using namespace std;

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

    if (posicionActual->arriba != nullptr &&
        !posicionActual->arriba->bloqueado) {

        posicionActual = posicionActual->arriba;

        aumentarPuntaje();
    }
}

void Detective::moverAbajo() {

    if (posicionActual->abajo != nullptr &&
        !posicionActual->abajo->bloqueado) {

        posicionActual = posicionActual->abajo;

        aumentarPuntaje();
    }
}

void Detective::moverIzquierda() {

    if (posicionActual->izquierda != nullptr &&
        !posicionActual->izquierda->bloqueado) {

        posicionActual = posicionActual->izquierda;

        aumentarPuntaje();
    }
}

void Detective::moverDerecha() {

    if (posicionActual->derecha != nullptr &&
        !posicionActual->derecha->bloqueado) {

        posicionActual = posicionActual->derecha;

        aumentarPuntaje();
    }
}

void Detective::agregarPista(Pista pista) {

    pistas.push(pista);
}

void Detective::mostrarPistas() {

    stack<Pista> copia = pistas;

    cout << endl;

    cout << "Pistas recolectadas:" << endl;

    while (!copia.empty()) {

        cout << copia.top().getTipo() << endl;

        copia.pop();
    }

    cout << endl;
}

void Detective::revisarPista() {

    if (posicionActual->tienePista) {

        Pista nueva(posicionActual->tipoPista);

        agregarPista(nueva);

        cout << endl;

        cout << "Has encontrado una pista tipo "
             << posicionActual->tipoPista
             << "!" << endl;

        posicionActual->tienePista = false;

        posicionActual->contenido = 'o';
    }
}

void Detective::agregarTestigo(Testigo testigo) {

    testigos.push(testigo);
}

void Detective::interrogarTestigo() {

    if (testigos.empty()) {

        cout << endl;
        cout << "No hay testigos en la cola." << endl;
        return;
    }

    Testigo actual = testigos.front();

    cout << endl;

    cout << "Declaracion del testigo:" << endl;

    cout << actual.getDeclaracion() << endl;

    testigos.pop();
}