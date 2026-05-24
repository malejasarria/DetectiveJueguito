#include "ColaTestigos.h"

ColaTestigos::ColaTestigos() {

    frente = nullptr;

    final = nullptr;
}

bool ColaTestigos::estaVacia() {

    return frente == nullptr;
}

void ColaTestigos::enqueue(Testigo t) {

    NodoCola* nuevo =
            new NodoCola(t);

    if (estaVacia()) {

        frente = nuevo;

        final = nuevo;

    } else {

        final->siguiente =
                nuevo;

        final = nuevo;
    }
}

void ColaTestigos::dequeue() {

    if (!estaVacia()) {

        NodoCola* temp =
                frente;

        frente =
                frente->siguiente;

        delete temp;

        if (frente == nullptr) {

            final = nullptr;
        }
    }
}

Testigo ColaTestigos::front() {

    return frente->dato;
}