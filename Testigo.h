#ifndef TESTIGO_H
#define TESTIGO_H

#include <string>

using namespace std;

class Testigo {

private:

    string declaracion;

public:

    Testigo(string d);

    string getDeclaracion();

};

#endif