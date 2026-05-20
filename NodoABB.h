#ifndef NODOABB_H
#define NODOABB_H

#include "Score.h"

class NodoABB {

public:

    Score score;

    NodoABB* izquierda;

    NodoABB* derecha;

    NodoABB(Score s);
};

#endif