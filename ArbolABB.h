#ifndef ARBOLABB_H
#define ARBOLABB_H

#include "NodoABB.h"

class ArbolABB {

private:

    NodoABB* raiz;

    NodoABB* insertarRecursivo(
            NodoABB* nodo,
            Sospechoso sospechoso);

    void inorderRecursivo(NodoABB* nodo);

public:

    ArbolABB();

    void insertar(Sospechoso sospechoso);

    void mostrarInorder();
};

#endif