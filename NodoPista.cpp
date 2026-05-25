#include "NodoPista.h"

NodoPista::NodoPista(char t) {

    tipo = t;

    siguiente = nullptr;
}

char NodoPista::getTipo() {

    return tipo;
}