#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>

using namespace std;

class Sospechoso {

private:

    string nombre;

    string crimen;

    string sexo;

    string cabello;

    string piel;

    string estatura;

public:

    Sospechoso();

    Sospechoso(
            string n,
            string c,
            string s,
            string cab,
            string p,
            string e);

    string getNombre() const;

    string getCrimen() const;

    string getSexo() const;

    string getCabello() const;

    string getPiel() const;

    string getEstatura() const;
};

#endif