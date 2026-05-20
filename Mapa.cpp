#include "Mapa.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Mapa::Mapa() {

    inicio = nullptr;

    crearMapa();

    generarCallejones();

    generarPistas();

    generarTestigos();
}

void Mapa::crearMapa() {

    Nodo* filaAnterior = nullptr;

    for (int i = 0; i < 9; i++) {

        Nodo* filaActual = nullptr;
        Nodo* anterior = nullptr;

        Nodo* arriba = filaAnterior;

        for (int j = 0; j < 9; j++) {

            Nodo* nuevo = new Nodo(i, j);

            if (inicio == nullptr) {

                inicio = nuevo;
            }

            if (filaActual == nullptr) {

                filaActual = nuevo;
            }

            if (anterior != nullptr) {

                anterior->derecha = nuevo;
                nuevo->izquierda = anterior;
            }

            if (arriba != nullptr) {

                nuevo->arriba = arriba;
                arriba->abajo = nuevo;

                arriba = arriba->derecha;
            }

            anterior = nuevo;
        }

        filaAnterior = filaActual;
    }
}

void Mapa::conectarNodos(Nodo* nodos[9][9]) {

}

void Mapa::generarCallejones() {

    int cantidad = 0;

    while (cantidad < 16) {

        Nodo* actual = obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            actual->contenido = '|';

            actual->bloqueado = true;

            cantidad++;
        }
    }
}

void Mapa::generarPistas() {

    int cantidad = 0;

    char tipos[4] = {'H', 'C', 'T', 'P'};

    while (cantidad < 10) {

        Nodo* actual = obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            int tipoAleatorio = rand() % 4;

            actual->contenido = tipos[tipoAleatorio];

            actual->tienePista = true;

            actual->tipoPista = tipos[tipoAleatorio];

            cantidad++;
        }
    }
}

void Mapa::generarTestigos() {

    int cantidad = 0;

    while (cantidad < 5) {

        Nodo* actual = obtenerNodoAleatorio();

        if (actual->contenido == 'o') {

            actual->contenido = 'W';

            actual->tieneTestigo = true;

            cantidad++;
        }
    }
}

void Mapa::imprimirMapa(Detective& detective) {

    Nodo* fila = inicio;

    cout << endl;

    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < 11; j++) {

            if (i == 0 || i == 10 || j == 0 || j == 10) {

                cout << "# ";

            } else {

                Nodo* actual = fila;

                for (int k = 1; k < j; k++) {

                    actual = actual->derecha;
                }

                if (actual == detective.getPosicion()) {

                    cout << "D ";

                } else {

                    cout << actual->contenido << " ";
                }
            }
        }

        cout << endl;

        if (i > 0 && i < 10) {

            fila = fila->abajo;
        }
    }
}

Nodo* Mapa::obtenerNodoAleatorio() {

    int filaRandom = rand() % 9;
    int columnaRandom = rand() % 9;

    Nodo* actual = inicio;

    for (int i = 0; i < filaRandom; i++) {

        actual = actual->abajo;
    }

    for (int j = 0; j < columnaRandom; j++) {

        actual = actual->derecha;
    }

    return actual;
}