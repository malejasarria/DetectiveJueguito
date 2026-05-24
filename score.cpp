#include "score.h"

Score::Score()
    : nombreDetective(""),
      puntos(0) {
}

Score::Score(string nombre, int pts)
    : nombreDetective(nombre),
      puntos(pts) {
}

string Score::getNombre() const {

    return nombreDetective;
}

int Score::getPuntos() const {

    return puntos;
}

void Score::setNombre(string nombre) {

    nombreDetective = nombre;
}

void Score::setPuntos(int pts) {

    puntos = pts;
}

bool Score::operator<(
        const Score& otro) const {

    return puntos < otro.puntos;
}

bool Score::operator>(
        const Score& otro) const {

    return puntos > otro.puntos;
}