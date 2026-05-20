#ifndef NODO_H
#define NODO_H

using namespace std;

class Nodo {

public:

    int fila;
    int columna;

    char contenido;

    bool descubierto;

    Nodo* arriba;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int f, int c);

};

#endif