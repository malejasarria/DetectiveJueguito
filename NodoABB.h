#ifndef NODOABB_H
#define NODOABB_H

#include "Sospechoso.h"

class NodoABB {

public:

    Sospechoso sospechoso;

    NodoABB* izquierda;

    NodoABB* derecha;

    NodoABB(Sospechoso s);
};

#endif