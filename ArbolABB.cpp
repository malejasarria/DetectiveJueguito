#include "ArbolABB.h"

#include <iostream>

using namespace std;

ArbolABB::ArbolABB() {

    raiz = nullptr;
}

NodoABB* ArbolABB::insertarRecursivo(
        NodoABB* nodo,
        Score score) {

    if (nodo == nullptr) {

        return new NodoABB(score);
    }

    if (score.getPuntos() <
        nodo->score.getPuntos()) {

        nodo->izquierda =
                insertarRecursivo(
                        nodo->izquierda,
                        score);

        } else {

            nodo->derecha =
                    insertarRecursivo(
                            nodo->derecha,
                            score);
        }

    return nodo;
}

void ArbolABB::insertar(Score score) {

    raiz = insertarRecursivo(
            raiz,
            score);
}

void ArbolABB::inorderRecursivo(
        NodoABB* nodo) {

    if (nodo == nullptr) {

        return;
    }

    inorderRecursivo(nodo->izquierda);

    cout << nodo->score.getNombre()
         << " -> "
         << nodo->score.getPuntos()
         << " puntos"
         << endl;

    inorderRecursivo(nodo->derecha);
}

void ArbolABB::mostrarInorder() {

    cout << endl;

    cout << "Ranking historico:"
         << endl;

    inorderRecursivo(raiz);

    cout << endl;
}