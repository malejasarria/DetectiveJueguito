#ifndef JUEGO_H
#define JUEGO_H

#include "Mapa.h"
#include "Detective.h"
#include "ArbolABB.h"
#include "HashSospechosos.h"

class Juego {

private:

    Mapa mapa;

    Detective detective;

    ArbolABB ranking;

    HashSospechosos sospechosos;

    bool terminado;

    void inicializarSospechosos();

    void generarCulpable();

    void procesarMovimiento(
            char opcion);

    void revisarCasilla();

    void mostrarControles();

public:

    Juego(string nombreDetective);

    void iniciar();
};

#endif