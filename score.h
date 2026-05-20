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

    string getNombre();

    int getPuntos();
};

#endif