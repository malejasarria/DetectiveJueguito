#ifndef JUEGO_H
#define JUEGO_H

#include "Mapa.h"
#include "Detective.h"
#include "ArbolABB.h"

class Juego {

private:

    Mapa mapa;

    Detective detective;

    ArbolABB ranking;

    void inicializarSospechosos();

    void inicializarDetective();

    void inicializarRanking();

    void mostrarMenu();

    void faseAcusacion();

public:

    Juego(string nombreDetective);

    void procesarMovimiento(
            char movimiento);

    void iniciar();
};

#endif