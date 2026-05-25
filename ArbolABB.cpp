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

    if (nuevo->dato.getNombre() ==
        raiz->dato.getNombre()) {

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

        mostrarRec(
                raiz->izquierda);

        cout << raiz->dato.getNombre()
             << " -> "
             << raiz->dato.getPuntos()
             << " puntos"
             << endl;

        mostrarRec(
                raiz->derecha);
    }
}

void ArbolABB::mostrarInorder() {

    cout << endl;

    cout << "Ranking historico:"
         << endl;

    mostrarRec(raiz);

    cout << endl;
}

bool ArbolABB::buscarRec(
        NodoABB* raiz,
        string nombre) {

    if (raiz == nullptr) {

        return false;
    }

    if (raiz->dato.getNombre()
        == nombre) {

        cout << endl;

        cout << nombre
             << " ya jugo."
             << endl;

        cout << "Mejor score: "
             << raiz->dato.getPuntos()
             << endl;

        return true;
    }

    return buscarRec(
                   raiz->izquierda,
                   nombre)
           ||
           buscarRec(
                   raiz->derecha,
                   nombre);
}

bool ArbolABB::buscarDetective(
        string nombre) {

    if (!buscarRec(
            raiz,
            nombre)) {

        cout << endl;

        cout << nombre
             << " no tiene registros."
             << endl;

        return false;
    }

    return true;
}