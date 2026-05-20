#include "Sospechoso.h"

Sospechoso::Sospechoso() {

    nombre = "";
    crimen = "";
    sexo = "";
    cabello = "";
    piel = "";
    estatura = "";
}

Sospechoso::Sospechoso(
        string n,
        string c,
        string s,
        string cab,
        string p,
        string e) {

    nombre = n;

    crimen = c;

    sexo = s;

    cabello = cab;

    piel = p;

    estatura = e;
}

string Sospechoso::getNombre() {

    return nombre;
}

string Sospechoso::getCrimen() {

    return crimen;
}

string Sospechoso::getSexo() {

    return sexo;
}

string Sospechoso::getCabello() {

    return cabello;
}

string Sospechoso::getPiel() {

    return piel;
}

string Sospechoso::getEstatura() {

    return estatura;
}