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

    for (int i = 0; i < FILAS; i++) {

        Nodo* izquierda = nullptr;

        Nodo* arriba = filaAnteriorInicio;

        for (int j = 0; j < COLUMNAS; j++) {

            Nodo* nuevo =
                    new Nodo(i, j);

            if (j == 0) {

                filaActualInicio = nuevo;

                if (inicio == nullptr) {

                    inicio = nuevo;
                }
            }

            if (izquierda != nullptr) {

                izquierda->derecha =
                        nuevo;

                nuevo->izquierda =
                        izquierda;
            }

            if (arriba != nullptr) {

                nuevo->arriba =
                        arriba;

                arriba->abajo =
                        nuevo;

                arriba =
                        arriba->derecha;
            }

            izquierda = nuevo;
        }

        filaAnteriorInicio =
                filaActualInicio;
    }

    generarPistas();

    generarBloqueos();

    generarTestigos();
}

void Mapa::generarPistas() {

    int pistas = 0;

    while (pistas < TOTAL_PISTAS) {

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
}

void Mapa::generarBloqueos() {

    int bloqueos = 0;

    while (bloqueos < TOTAL_BLOQUEOS) {

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
}

void Mapa::generarTestigos() {

    int testigos = 0;

    while (testigos < TOTAL_TESTIGOS) {

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
        Detective& detective) {

    Nodo* filaActual = inicio;

    cout << endl;

    for (int i = 0; i < COLUMNAS + 2; i++) {

        cout << "# ";
    }

    cout << endl;

    for (int i = 0; i < FILAS; i++) {

        cout << "# ";

        Nodo* columnaActual =
                filaActual;

        for (int j = 0; j < COLUMNAS; j++) {

            if (columnaActual ==
                detective.getPosicion()) {

                cout << "D ";

                columnaActual->descubierto =
                        true;

            } else {

                if (!columnaActual->descubierto) {

                    cout << "o ";

                } else {

                    cout << columnaActual->contenido
                         << " ";
                }
            }

            columnaActual =
                    columnaActual->derecha;
        }

        cout << "#" << endl;

        filaActual =
                filaActual->abajo;
    }

    for (int i = 0; i < COLUMNAS + 2; i++) {

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
            rand() % FILAS;

    int columna =
            rand() % COLUMNAS;

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

    int intentos = 0;

    while (abiertas < 2 &&
           intentos < 100) {

        Nodo* actual =
                obtenerNodoAleatorio();

        if (actual->bloqueado) {

            actual->bloqueado =
                    false;

            actual->contenido =
                    ' ';

            abiertas++;
        }

        intentos++;
    }

    cout << endl;

    cout << "Dos callejones fueron abiertos."
         << endl;
}