#include "Detective.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Detective::Detective(string nom) {

    nombre = nom;

    puntaje = 0;

    posicionActual = nullptr;
}

void Detective::setPosicion(Nodo* nodo) {

    posicionActual = nodo;
}

Nodo* Detective::getPosicion() {

    return posicionActual;
}

string Detective::getNombre() {

    return nombre;
}

int Detective::getPuntaje() {

    return puntaje;
}

void Detective::aumentarPuntaje() {

    puntaje++;
}

void Detective::setPuntaje(int p) {

    puntaje = p;
}

void Detective::moverArriba() {

    if (posicionActual->arriba != nullptr &&
        !posicionActual->arriba->bloqueado) {

        posicionActual = posicionActual->arriba;

        aumentarPuntaje();
    }
}

void Detective::moverAbajo() {

    if (posicionActual->abajo != nullptr &&
        !posicionActual->abajo->bloqueado) {

        posicionActual = posicionActual->abajo;

        aumentarPuntaje();
    }
}

void Detective::moverIzquierda() {

    if (posicionActual->izquierda != nullptr &&
        !posicionActual->izquierda->bloqueado) {

        posicionActual = posicionActual->izquierda;

        aumentarPuntaje();
    }
}

void Detective::moverDerecha() {

    if (posicionActual->derecha != nullptr &&
        !posicionActual->derecha->bloqueado) {

        posicionActual = posicionActual->derecha;

        aumentarPuntaje();
    }
}

void Detective::agregarPista(Pista pista) {

    pistas.push(pista);
}

void Detective::mostrarPistas() {

    stack<Pista> copia = pistas;

    cout << endl;

    cout << "Pistas recolectadas:" << endl;

    while (!copia.empty()) {

        cout << copia.top().getTipo() << endl;

        copia.pop();
    }

    cout << endl;
}

void Detective::revisarPista() {

    if (posicionActual->tienePista) {

        Pista nueva(posicionActual->tipoPista);

        agregarPista(nueva);

        cout << endl;

        cout << "Has encontrado una pista tipo "
             << posicionActual->tipoPista
             << "!" << endl;

        posicionActual->tienePista = false;

        posicionActual->contenido = 'o';
    }
}

char Detective::usarPista() {

    if (pistas.empty()) {

        cout << endl;

        cout << "No tienes pistas."
             << endl;

        return 'N';
    }

    Pista ultima = pistas.top();

    pistas.pop();

    cout << endl;

    switch (ultima.getTipo()) {

        case 'H':

            cout << "Pista H usada:"
                 << endl;

            puntaje = puntaje / 2;

            cout << "El culpable tiene cabello "
                 << culpableReal.getCabello()
                 << "." << endl;

            cout << "Tu puntaje fue reducido a la mitad."
                 << endl;

            break;

        case 'C':

            cout << "Pista C usada:"
                 << endl;

            cout << "El culpable tiene piel "
                 << culpableReal.getPiel()
                 << "." << endl;

            break;

        case 'T': {

            cout << "Pista T usada:"
                 << endl;

            cout << "El culpable es de estatura "
                 << culpableReal.getEstatura()
                 << "." << endl;

            int evento;

            evento = rand() % 2;

            if (evento == 0) {

                puntaje = 0;

                cout << "Tu puntaje fue reiniciado a 0."
                     << endl;

            } else {

                puntaje = puntaje * 2;

                cout << "Tu puntaje fue multiplicado por 2."
                     << endl;
            }

            break;
        }

        case 'P':

            cout << "Pista P usada:"
                 << endl;

            cout << "El culpable es "
                 << culpableReal.getSexo()
                 << "." << endl;

            cout << "La pista fue utilizada."
                 << endl;

            break;
    }

    cout << endl;

    return ultima.getTipo();
}

void Detective::agregarTestigo(Testigo testigo) {

    testigos.push(testigo);
}

void Detective::interrogarTestigo() {

    if (testigos.empty()) {

        cout << endl;

        cout << "No hay testigos en la cola."
             << endl;

        return;
    }

    Testigo actual = testigos.front();

    cout << endl;

    cout << "Declaracion del testigo:"
         << endl;

    cout << actual.getDeclaracion()
         << endl;

    testigos.pop();
}

void Detective::agregarSospechoso(
        Sospechoso sospechoso) {

    sospechosos[sospechoso.getNombre()]
            = sospechoso;
}

void Detective::mostrarSospechosos() {

    cout << endl;

    cout << "Lista de sospechosos:"
         << endl;

    for (auto& par : sospechosos) {

        cout << endl;

        cout << "Nombre: "
             << par.second.getNombre()
             << endl;

        cout << "Crimen: "
             << par.second.getCrimen()
             << endl;

        cout << "Sexo: "
             << par.second.getSexo()
             << endl;

        cout << "Cabello: "
             << par.second.getCabello()
             << endl;

        cout << "Piel: "
             << par.second.getPiel()
             << endl;

        cout << "Estatura: "
             << par.second.getEstatura()
             << endl;
    }

    cout << endl;
}

void Detective::setCulpable(
        Sospechoso sospechoso) {

    culpableReal = sospechoso;
}

Sospechoso Detective::getCulpable() {

    return culpableReal;
}

int Detective::cantidadPistas() {

    return pistas.size();
}

bool Detective::acusar(string nombre) {

    return nombre ==
           culpableReal.getNombre();
}