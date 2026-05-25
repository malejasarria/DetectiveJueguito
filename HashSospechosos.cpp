#include "HashSospechosos.h"

#include <iostream>

using namespace std;

HashSospechosos::HashSospechosos() {

    for (int i = 0; i < TAM; i++) {

        tabla[i] =
                Sospechoso();
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

    while (tabla[indice].getNombre()
           != "") {

        indice =
                (indice + 1) % TAM;
           }

    tabla[indice] =
            sospechoso;
}

Sospechoso* HashSospechosos::buscar(
        string nombre) {

    int indice =
            funcionHash(nombre);

    int inicio =
            indice;

    while (tabla[indice].getNombre()
           != "") {

        if (tabla[indice].getNombre()
            == nombre) {

            return &tabla[indice];
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

        if (tabla[i].getNombre()
            != "") {

            cout << i
                 << " -> "
                 << tabla[i].getNombre()
                 << endl;
            }
    }

    cout << endl;
}

Sospechoso* HashSospechosos::getTabla() {

    return tabla;
}