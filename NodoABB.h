#ifndef NODOABB_H
#define NODOABB_H

#include "score.h"

class NodoABB {

public:

    Score dato;

    NodoABB* izquierda;

    NodoABB* derecha;

    NodoABB(Score d);
};

#endif