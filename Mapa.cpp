#include "Mapa.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Mapa::Mapa() {

    crearMapa();
}

void Mapa::crearMapa() {

    inicio = nullptr;

    Nodo* filaAnteriorInicio = nullptr;

    Nodo* filaActualInicio = nullptr;

    for (int i = 0; i < 9; i++) {

        Nodo* actual = nullptr;

        Nodo* izquierda = nullptr;

        Nodo* arriba = filaAnteriorInicio;

        for (int j = 0; j < 9; j++) {

            Nodo* nuevo = new Nodo(i, j);

            if (j == 0) {

                filaActualInicio = nuevo;

                if (inicio == nullptr) {

                    inicio = nuevo;
                }
            }

            if (izquierda != nullptr) {

                izquierda->derecha = nuevo;

                nuevo->izquierda = izquierda;
            }

            if (arriba != nullptr) {

                nuevo->arriba = arriba;

                arriba->abajo = nuevo;

                arriba = arriba->derecha;
            }

            izquierda = nuevo;

            actual = nuevo;
        }

        filaAnteriorInicio = filaActualInicio;
    }

    int pistas = 0;

    while (pistas < 10) {

        Nodo* actual =
                obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            char tipos[4] =
                    {'H', 'C', 'T', 'P'};

            char tipo =
                    tipos[rand() % 4];

            actual->contenido =
                    tipo;

            actual->tienePista =
                    true;

            actual->tipoPista =
                    tipo;

            pistas++;
        }
    }

    int bloqueos = 0;

    while (bloqueos < 16) {

        Nodo* actual =
                obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            actual->contenido =
                    '|';

            actual->bloqueado =
                    true;

            bloqueos++;
        }
    }

    int testigos = 0;

    while (testigos < 5) {

        Nodo* actual =
                obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            actual->contenido =
                    'W';

            actual->tieneTestigo =
                    true;

            testigos++;
        }
    }
}

void Mapa::imprimirMapa(
        Detective detective) {

    Nodo* filaActual = inicio;

    cout << endl;

    for (int i = 0; i < 11; i++) {

        cout << "# ";
    }

    cout << endl;

    for (int i = 0; i < 9; i++) {

        cout << "# ";

        Nodo* columnaActual =
                filaActual;

        for (int j = 0; j < 9; j++) {

            if (columnaActual ==
                detective.getPosicion()) {

                cout << "D ";

            } else {

                cout << columnaActual->contenido
                     << " ";
            }

            columnaActual =
                    columnaActual->derecha;
        }

        cout << "#" << endl;

        filaActual =
                filaActual->abajo;
    }

    for (int i = 0; i < 11; i++) {

        cout << "# ";
    }

    cout << endl;
}

Nodo* Mapa::obtenerInicio() {

    return inicio;
}

Nodo* Mapa::obtenerNodoAleatorio() {

    Nodo* actual = inicio;

    int fila =
            rand() % 9;

    int columna =
            rand() % 9;

    for (int i = 0; i < fila; i++) {

        actual =
                actual->abajo;
    }

    for (int j = 0; j < columna; j++) {

        actual =
                actual->derecha;
    }

    return actual;
}

void Mapa::abrirCalles() {

    int abiertas = 0;

    while (abiertas < 2) {

        Nodo* actual =
                obtenerNodoAleatorio();

        if (actual->bloqueado) {

            actual->bloqueado =
                    false;

            actual->contenido =
                    'o';

            abiertas++;
        }
    }

    cout << endl;

    cout << "Dos callejones fueron abiertos."
         << endl;
}