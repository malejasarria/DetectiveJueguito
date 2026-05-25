#ifndef ARBOLABB_H
#define ARBOLABB_H

#include "NodoABB.h"

class ArbolABB {

private:

        NodoABB* raiz;

        NodoABB* insertarRec(
                NodoABB* raiz,
                NodoABB* nuevo);

        void mostrarRec(
                NodoABB* raiz);

        bool buscarRec(
                NodoABB* raiz,
                string nombre);

public:

        ArbolABB();

        void insertar(Score dato);

        void mostrarInorder();

        bool buscarDetective(
                string nombre);
};

#endif