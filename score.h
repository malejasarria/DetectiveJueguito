#ifndef SCORE_H
#define SCORE_H

#include <string>

using namespace std;

class Score {

private:

    string nombreDetective;

    int puntos;

public:

    Score();

    Score(string nombre, int pts);

    string getNombre() const;

    int getPuntos() const;

    void setNombre(string nombre);

    void setPuntos(int pts);

    bool operator<(const Score& otro) const;

    bool operator>(const Score& otro) const;
};

#endif