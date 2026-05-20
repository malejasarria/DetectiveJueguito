#include "Sospechoso.h"

Sospechoso::Sospechoso() {

    nombre = "";
    crimen = "";
}

Sospechoso::Sospechoso(string n, string c) {

    nombre = n;
    crimen = c;
}

string Sospechoso::getNombre() {

    return nombre;
}

string Sospechoso::getCrimen() {

    return crimen;
}