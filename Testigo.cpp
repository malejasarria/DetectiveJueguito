#include "Testigo.h"

Testigo::Testigo()

    : declaracion("") {
}

Testigo::Testigo(string d)

    : declaracion(d) {
}

string Testigo::getDeclaracion() const {

    return declaracion;
}