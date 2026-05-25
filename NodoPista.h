#ifndef NODOPISTA_H
#define NODOPISTA_H

class NodoPista {

private:

    char tipo;

public:

    NodoPista* siguiente;

    NodoPista(char t);

    char getTipo();
};

#endif