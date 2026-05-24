#include "Detective.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Detective::Detective(
        string nom) {

    nombre = nom;

    puntaje = 0;

    posicionActual = nullptr;

    cabelloDescubierto = false;

    pielDescubierta = false;

    sexoDescubierto = false;

    estaturaDescubierta = false;
}

void Detective::setPosicion(
        Nodo* nodo) {

    posicionActual = nodo;
}

Nodo* Detective::getPosicion() {

    return posicionActual;
}

string Detective::getNombre() const {

    return nombre;
}

int Detective::getPuntaje() const {

    return puntaje;
}

void Detective::aumentarPuntaje() {

    puntaje++;
}

void Detective::setPuntaje(
        int p) {

    puntaje = p;
}

void Detective::moverArriba() {

    if (posicionActual->arriba != nullptr &&
        !posicionActual->arriba->bloqueado) {

        posicionActual =
                posicionActual->arriba;

        aumentarPuntaje();
    }
}

void Detective::moverAbajo() {

    if (posicionActual->abajo != nullptr &&
        !posicionActual->abajo->bloqueado) {

        posicionActual =
                posicionActual->abajo;

        aumentarPuntaje();
    }
}

void Detective::moverIzquierda() {

    if (posicionActual->izquierda != nullptr &&
        !posicionActual->izquierda->bloqueado) {

        posicionActual =
                posicionActual->izquierda;

        aumentarPuntaje();
    }
}

void Detective::moverDerecha() {

    if (posicionActual->derecha != nullptr &&
        !posicionActual->derecha->bloqueado) {

        posicionActual =
                posicionActual->derecha;

        aumentarPuntaje();
    }
}

void Detective::agregarPista(
        char tipo) {

    pistas.push(tipo);
}

void Detective::mostrarPistas() {

    pistas.mostrar();
}

void Detective::revisarPista() {

    if (posicionActual->tienePista) {

        agregarPista(
                posicionActual->tipoPista);

        cout << endl;

        cout << "Has encontrado una pista tipo "
             << posicionActual->tipoPista
             << "!"
             << endl;

        posicionActual->tienePista =
                false;

        posicionActual->contenido =
                'o';
    }
}

char Detective::usarPista() {

    if (pistas.estaVacia()) {

        cout << endl;

        cout << "No tienes pistas."
             << endl;

        return 'N';
    }

    char ultima =
            pistas.top();

    pistas.pop();

    cout << endl;

    switch (ultima) {

        case 'H':

            cout << "Pista H usada:"
                 << endl;

            puntaje =
                    puntaje / 2;

            cout << "El culpable tiene cabello "
                 << culpableReal.getCabello()
                 << "."
                 << endl;

            cabelloDescubierto =
                    true;

            cout << "Tu puntaje fue reducido a la mitad."
                 << endl;

            break;

        case 'C':

            cout << "Pista C usada:"
                 << endl;

            cout << "El culpable tiene piel "
                 << culpableReal.getPiel()
                 << "."
                 << endl;

            pielDescubierta =
                    true;

            break;

        case 'T': {

            cout << "Pista T usada:"
                 << endl;

            cout << "El culpable es de estatura "
                 << culpableReal.getEstatura()
                 << "."
                 << endl;

            estaturaDescubierta =
                    true;

            int evento =
                    rand() % 2;

            if (evento == 0) {

                puntaje = 0;

                cout << "Tu puntaje fue reiniciado a 0."
                     << endl;

            } else {

                puntaje =
                        puntaje * 2;

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
                 << "."
                 << endl;

            sexoDescubierto =
                    true;

            cout << "La pista fue utilizada."
                 << endl;

            break;
    }

    cout << endl;

    return ultima;
}

void Detective::agregarTestigo(
        Testigo testigo) {

    testigos.enqueue(testigo);
}

void Detective::interrogarTestigo() {

    if (testigos.estaVacia()) {

        cout << endl;

        cout << "No hay testigos en la cola."
             << endl;

        return;
    }

    Testigo actual =
            testigos.front();

    cout << endl;

    cout << "Declaracion del testigo:"
         << endl;

    cout << actual.getDeclaracion()
         << endl;

    testigos.dequeue();
}

void Detective::agregarSospechoso(
        Sospechoso sospechoso) {

    sospechosos.insertar(
            sospechoso);
}

void Detective::mostrarSospechosos() {

    sospechosos.mostrar();

    cout << endl;

    cout << "Atributos descubiertos:"
         << endl;

    cout << endl;

    cout << "Sexo: ";

    if (sexoDescubierto) {

        cout << culpableReal.getSexo();

    } else {

        cout << "?";
    }

    cout << endl;

    cout << "Cabello: ";

    if (cabelloDescubierto) {

        cout << culpableReal.getCabello();

    } else {

        cout << "?";
    }

    cout << endl;

    cout << "Piel: ";

    if (pielDescubierta) {

        cout << culpableReal.getPiel();

    } else {

        cout << "?";
    }

    cout << endl;

    cout << "Estatura: ";

    if (estaturaDescubierta) {

        cout << culpableReal.getEstatura();

    } else {

        cout << "?";
    }

    cout << endl << endl;
}

void Detective::setCulpable(
        Sospechoso sospechoso) {

    culpableReal =
            sospechoso;
}

Sospechoso Detective::getCulpable() const {

    return culpableReal;
}

int Detective::cantidadPistas() {

    return 0;
}

bool Detective::acusar(
        string nombre) {

    return nombre ==
           culpableReal.getNombre();
}