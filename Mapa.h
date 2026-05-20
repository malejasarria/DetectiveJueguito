#ifndef MAPA_H
#define MAPA_H

#include "Nodo.h"
#include "Detective.h"

class Mapa {

private:

    Nodo* inicio;

public:

    Mapa();

    void crearMapa();

    void conectarNodos(Nodo* nodos[9][9]);

    void imprimirMapa(Detective& detective);

    Nodo* obtenerNodoAleatorio();

};

#endif