#include "PilaPistas.h"

#include <iostream>

using namespace std;

PilaPistas::PilaPistas() {

    cima = nullptr;
}

bool PilaPistas::estaVacia() {

    return cima == nullptr;
}

void PilaPistas::push(char tipo) {

    NodoPista* nuevo =
            new NodoPista(tipo);

    nuevo->siguiente =
            cima;

    cima = nuevo;
}

void PilaPistas::pop() {

    if (!estaVacia()) {

        NodoPista* temp =
                cima;

        cima =
                cima->siguiente;

        delete temp;
    }
}

char PilaPistas::top() {

    if (!estaVacia()) {

        return cima->tipoPista;
    }

    return ' ';
}

void PilaPistas::mostrar() {

    NodoPista* actual =
            cima;

    cout << endl;

    cout << "Pistas recolectadas:"
         << endl;

    while (actual != nullptr) {

        cout << actual->tipoPista
             << endl;

        actual =
                actual->siguiente;
    }
}