#ifndef PILAPISTAS_H
#define PILAPISTAS_H

#include "NodoPista.h"

class PilaPistas {

private:

    NodoPista* cima;

public:

    PilaPistas();

    bool estaVacia();

    void push(char tipo);

    void pop();

    char top();

    void mostrar();
};

#endif