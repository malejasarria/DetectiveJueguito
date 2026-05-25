#include "Sospechoso.h"

Sospechoso::Sospechoso()

    : nombre(""),
      crimen(""),
      sexo(""),
      cabello(""),
      piel(""),
      estatura("") {
}

Sospechoso::Sospechoso(
        string n,
        string c,
        string s,
        string cab,
        string p,
        string e)

    : nombre(n),
      crimen(c),
      sexo(s),
      cabello(cab),
      piel(p),
      estatura(e) {
}

string Sospechoso::getNombre() const {

    return nombre;
}

string Sospechoso::getCrimen() const {

    return crimen;
}

string Sospechoso::getSexo() const {

    return sexo;
}

string Sospechoso::getCabello() const {

    return cabello;
}

string Sospechoso::getPiel() const {

    return piel;
}

string Sospechoso::getEstatura() const {

    return estatura;
}