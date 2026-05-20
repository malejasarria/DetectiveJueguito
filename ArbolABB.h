#ifndef ARBOLABB_H
#define ARBOLABB_H

#include "NodoABB.h"

#include <string>

using namespace std;

class ArbolABB {

private:

    NodoABB* raiz;

    NodoABB* insertarRec(
            NodoABB* raiz,
            NodoABB* nuevo);

    void mostrarRec(
            NodoABB* raiz);

public:

    ArbolABB();

    void insertar(Score dato);

    void mostrarInorder();

    bool buscarDetective(
            string nombre);
};

#endif