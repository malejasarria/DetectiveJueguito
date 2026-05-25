#ifndef HASHSOSPECHOSOS_H
#define HASHSOSPECHOSOS_H

#include "Sospechoso.h"

#include <string>

using namespace std;

class HashSospechosos {

private:

    static const int TAM = 20;

    Sospechoso tabla[TAM];

    int funcionHash(
            string nombre);

public:

    HashSospechosos();

    void insertar(
            Sospechoso sospechoso);

    Sospechoso* buscar(
            string nombre);

    void mostrar();

    Sospechoso* getTabla();
};

#endif