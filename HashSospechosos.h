#ifndef HASHSOSPECHOSOS_H
#define HASHSOSPECHOSOS_H

#include "Sospechoso.h"

#include <string>

using namespace std;

class HashSospechosos {

private:

    static const int TAM = 20;

    Sospechoso* tabla[TAM];

public:

    HashSospechosos();

    ~HashSospechosos();

    int funcionHash(
            string nombre);

    void insertar(
            Sospechoso sospechoso);

    Sospechoso* buscar(
            string nombre);

    void mostrar();
};

#endif