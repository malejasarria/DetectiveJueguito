#ifndef NODOCOLA_H
#define NODOCOLA_H

#include "Testigo.h"

class NodoCola {

public:

    Testigo dato;

    NodoCola* siguiente;

    NodoCola(Testigo t);
};

#endif