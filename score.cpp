#include "Score.h"

Score::Score() {

    nombreDetective = "";

    puntos = 0;
}

Score::Score(string nombre, int pts) {

    nombreDetective = nombre;

    puntos = pts;
}

string Score::getNombre() {

    return nombreDetective;
}

int Score::getPuntos() {

    return puntos;
}