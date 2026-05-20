#include "Mapa.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Mapa::Mapa() {

    inicio = nullptr;

    crearMapa();
}

void Mapa::crearMapa() {

    Nodo* nodos[9][9];

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            nodos[i][j] = new Nodo(i, j);
        }
    }

    conectarNodos(nodos);

    inicio = nodos[0][0];
}

void Mapa::conectarNodos(Nodo* nodos[9][9]) {

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            if (i > 0)
                nodos[i][j]->arriba = nodos[i - 1][j];

            if (i < 8)
                nodos[i][j]->abajo = nodos[i + 1][j];

            if (j > 0)
                nodos[i][j]->izquierda = nodos[i][j - 1];

            if (j < 8)
                nodos[i][j]->derecha = nodos[i][j + 1];
        }
    }
}

void Mapa::imprimirMapa(Detective& detective) {

    Nodo* filaActual = inicio;

    cout << endl;

    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < 11; j++) {

            if (i == 0 || i == 10 || j == 0 || j == 10) {

                cout << "# ";

            } else {

                Nodo* actual = filaActual;

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

            filaActual = filaActual->abajo;
        }
    }
}

Nodo* Mapa::obtenerNodoAleatorio() {

    int fila = rand() % 9;
    int columna = rand() % 9;

    Nodo* actual = inicio;

    for (int i = 0; i < fila; i++) {

        actual = actual->abajo;
    }

    for (int j = 0; j < columna; j++) {

        actual = actual->derecha;
    }

    return actual;
}