#include "Detective.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Detective::Detective(string nom) {

    nombre = nom;

    puntaje = 0;

    posicionActual = nullptr;

    totalPistas = 0;

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

    if (posicionActual->arriba != nullptr) {

        if (posicionActual->arriba->bloqueado) {

            cout << endl;

            cout << "Hay un callejon cerrado arriba."
                 << endl;

            return;
        }

        posicionActual =
                posicionActual->arriba;

        aumentarPuntaje();
    }
}

void Detective::moverAbajo() {

    if (posicionActual->abajo != nullptr) {

        if (posicionActual->abajo->bloqueado) {

            cout << endl;

            cout << "Hay un callejon cerrado abajo."
                 << endl;

            return;
        }

        posicionActual =
                posicionActual->abajo;

        aumentarPuntaje();
    }
}

void Detective::moverIzquierda() {

    if (posicionActual->izquierda != nullptr) {

        if (posicionActual->izquierda->bloqueado) {

            cout << endl;

            cout << "Hay un callejon cerrado a la izquierda."
                 << endl;

            return;
        }

        posicionActual =
                posicionActual->izquierda;

        aumentarPuntaje();
    }
}

void Detective::moverDerecha() {

    if (posicionActual->derecha != nullptr) {

        if (posicionActual->derecha->bloqueado) {

            cout << endl;

            cout << "Hay un callejon cerrado a la derecha."
                 << endl;

            return;
        }

        posicionActual =
                posicionActual->derecha;

        aumentarPuntaje();
    }
}

void Detective::agregarPista(
        char tipo) {

    pistas.push(tipo);

    totalPistas++;
}

void Detective::mostrarPistas() {

    cout << endl;

    cout << "Pistas recolectadas:"
         << endl;

    pistas.mostrar();

    cout << endl;
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

    cout << endl;

    cout << nombre
         << ", sospechosos del caso:"
         << endl;

    cout << endl;

    Sospechoso* tabla =
            sospechosos.getTabla();

    for (int i = 0; i < 20; i++) {

        if (tabla[i].getNombre() != "") {

            cout << tabla[i].getNombre()
                 << endl;

            cout << "Sexo: ";

            if (sexoDescubierto) {

                cout << tabla[i].getSexo();

            } else {

                cout << "?";
            }

            cout << endl;

            cout << "Cabello: ";

            if (cabelloDescubierto) {

                cout << tabla[i].getCabello();

            } else {

                cout << "?";
            }

            cout << endl;

            cout << "Piel: ";

            if (pielDescubierta) {

                cout << tabla[i].getPiel();

            } else {

                cout << "?";
            }

            cout << endl;

            cout << "Estatura: ";

            if (estaturaDescubierta) {

                cout << tabla[i].getEstatura();

            } else {

                cout << "?";
            }

            cout << endl;

            cout << "Crimen: "
                 << tabla[i].getCrimen()
                 << endl;

            cout << endl;
        }
    }
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

    return totalPistas;
}

bool Detective::acusar(
        string nombre) {

    return nombre ==
           culpableReal.getNombre();
}