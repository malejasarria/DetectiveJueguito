#include "Nodo.h"

Nodo::Nodo(int f, int c) {

    fila = f;
    columna = c;

    contenido = 'o';

    descubierto = false;

    arriba = nullptr;
    abajo = nullptr;
    izquierda = nullptr;
    derecha = nullptr;
}