#include "ArbolABB.h"

#include <iostream>

using namespace std;

ArbolABB::ArbolABB() {

    raiz = nullptr;
}

NodoABB* ArbolABB::insertarRec(
        NodoABB* raiz,
        NodoABB* nuevo) {

    if (raiz == nullptr) {

        return nuevo;
    }

    if (nuevo->nombreDetective ==
        raiz->nombreDetective) {

        if (nuevo->dato.getPuntos() <
            raiz->dato.getPuntos()) {

            raiz->dato =
                    nuevo->dato;
            }

        return raiz;
        }

    if (nuevo->dato.getPuntos() <
        raiz->dato.getPuntos()) {

        raiz->izquierda =
                insertarRec(
                        raiz->izquierda,
                        nuevo);

        } else {

            raiz->derecha =
                    insertarRec(
                            raiz->derecha,
                            nuevo);
        }

    return raiz;
}

void ArbolABB::insertar(Score dato) {

    NodoABB* nuevo =
            new NodoABB(dato);

    raiz = insertarRec(
            raiz,
            nuevo);
}

void ArbolABB::mostrarRec(
        NodoABB* raiz) {

    if (raiz != nullptr) {

        mostrarRec(raiz->izquierda);

        cout << raiz->dato.getNombre()
             << " -> "
             << raiz->dato.getPuntos()
             << " puntos"
             << endl;

        mostrarRec(raiz->derecha);
    }
}

void ArbolABB::mostrarInorder() {

    cout << endl;

    cout << "Ranking historico:"
         << endl;

    mostrarRec(raiz);

    cout << endl;
}