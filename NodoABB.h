#ifndef NODOABB_H
#define NODOABB_H

#include "Score.h"

#include <string>

using namespace std;

class NodoABB {

public:

    Score dato;

    string nombreDetective;

    NodoABB* izquierda;

    NodoABB* derecha;

    NodoABB(Score d);
};

#endif