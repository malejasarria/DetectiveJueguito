#include "Nodo.h"

Nodo::Nodo(int f, int c) {

    fila = f;
    columna = c;

    contenido = 'o';

    bloqueado = false;

    tienePista = false;

    tipoPista = ' ';

    tieneTestigo = false;

    descubierto = false;

    arriba = nullptr;
    abajo = nullptr;
    izquierda = nullptr;
    derecha = nullptr;
}