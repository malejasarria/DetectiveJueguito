#ifndef COLATESTIGOS_H
#define COLATESTIGOS_H

#include "NodoCola.h"

class ColaTestigos {

private:

    NodoCola* frente;

    NodoCola* final;

public:

    ColaTestigos();

    bool estaVacia();

    void enqueue(Testigo t);

    void dequeue();

    Testigo front();
};

#endif