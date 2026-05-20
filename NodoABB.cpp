#include "NodoABB.h"

NodoABB::NodoABB(Score d) {

    dato = d;

    nombreDetective =
            d.getNombre();

    izquierda = nullptr;

    derecha = nullptr;
}