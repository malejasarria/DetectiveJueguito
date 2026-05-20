#ifndef SOSPECHOSO_H
#define SOSPECHOSO_H

#include <string>

using namespace std;

class Sospechoso {

private:

    string nombre;

    string crimen;

public:

    Sospechoso();

    Sospechoso(string n, string c);

    string getNombre();

    string getCrimen();
};

#endif