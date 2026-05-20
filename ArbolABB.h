#ifndef ARBOLABB_H
#define ARBOLABB_H

#include "NodoABB.h"

class ArbolABB {

private:

    NodoABB* raiz;

    NodoABB* insertarRecursivo(
            NodoABB* nodo,
            Score score);

    void inorderRecursivo(NodoABB* nodo);

public:

    ArbolABB();

    void insertar(Score score);

    void mostrarInorder();
};

#endif