#ifndef MAPA_H
#define MAPA_H

#include "Nodo.h"
#include "Detective.h"

class Mapa {

private:

    Nodo* inicio;

    static const int FILAS = 9;
    static const int COLUMNAS = 9;

    static const int TOTAL_PISTAS = 10;
    static const int TOTAL_BLOQUEOS = 16;
    static const int TOTAL_TESTIGOS = 5;

    void generarPistas();

    void generarBloqueos();

    void generarTestigos();

public:

    Mapa();

    void crearMapa();

    void imprimirMapa(
            Detective& detective);

    Nodo* obtenerInicio();

    Nodo* obtenerNodoAleatorio();

    void abrirCalles();
};

#endif