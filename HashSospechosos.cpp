#include "HashSospechosos.h"

#include <iostream>

using namespace std;

HashSospechosos::HashSospechosos() {

    for (int i = 0; i < TAM; i++) {

        tabla[i] = nullptr;
    }
}

HashSospechosos::~HashSospechosos() {

    for (int i = 0; i < TAM; i++) {

        if (tabla[i] != nullptr) {

            delete tabla[i];

            tabla[i] = nullptr;
        }
    }
}

int HashSospechosos::funcionHash(
        string nombre) {

    int suma = 0;

    for (char letra : nombre) {

        suma += letra;
    }

    return suma % TAM;
}

void HashSospechosos::insertar(
        Sospechoso sospechoso) {

    int indice =
            funcionHash(
                    sospechoso.getNombre());

    int inicio = indice;

    while (tabla[indice] != nullptr) {

        indice =
                (indice + 1) % TAM;

        if (indice == inicio) {

            cout << endl;

            cout << "La tabla hash esta llena."
                 << endl;

            return;
        }
    }

    tabla[indice] =
            new Sospechoso(sospechoso);
}

Sospechoso* HashSospechosos::buscar(
        string nombre) {

    int indice =
            funcionHash(nombre);

    int inicio = indice;

    while (tabla[indice] != nullptr) {

        if (tabla[indice]->getNombre()
            == nombre) {

            return tabla[indice];
            }

        indice =
                (indice + 1) % TAM;

        if (indice == inicio) {

            break;
        }
    }

    return nullptr;
}

void HashSospechosos::mostrar() {

    cout << endl;

    cout << "Tabla Hash:"
         << endl;

    for (int i = 0; i < TAM; i++) {

        cout << i << " -> ";

        if (tabla[i] != nullptr) {

            cout << tabla[i]->getNombre();

        } else {

            cout << "vacio";
        }

        cout << endl;
    }

    cout << endl;
}