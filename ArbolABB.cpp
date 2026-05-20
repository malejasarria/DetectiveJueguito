#include "ArbolABB.h"

#include <iostream>

using namespace std;

ArbolABB::ArbolABB() {

    raiz = nullptr;
}

NodoABB* ArbolABB::insertarRecursivo(
        NodoABB* nodo,
        Sospechoso sospechoso) {

    if (nodo == nullptr) {

        return new NodoABB(sospechoso);
    }

    if (sospechoso.getNombre() <
        nodo->sospechoso.getNombre()) {

        nodo->izquierda =
                insertarRecursivo(
                        nodo->izquierda,
                        sospechoso);

        } else {

            nodo->derecha =
                    insertarRecursivo(
                            nodo->derecha,
                            sospechoso);
        }

    return nodo;
}

void ArbolABB::insertar(Sospechoso sospechoso) {

    raiz = insertarRecursivo(
            raiz,
            sospechoso);
}

void ArbolABB::inorderRecursivo(NodoABB* nodo) {

    if (nodo == nullptr) {

        return;
    }

    inorderRecursivo(nodo->izquierda);

    cout << nodo->sospechoso.getNombre()
         << " - "
         << nodo->sospechoso.getCrimen()
         << endl;

    inorderRecursivo(nodo->derecha);
}

void ArbolABB::mostrarInorder() {

    cout << endl;

    cout << "Sospechosos ordenados:"
         << endl;

    inorderRecursivo(raiz);

    cout << endl;
}