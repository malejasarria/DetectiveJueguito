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

    void imprimirMapa(
            Detective detective);

    Nodo* obtenerInicio();

    Nodo* obtenerNodoAleatorio();

    void abrirCalles();
};

#endif