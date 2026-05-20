#include "Mapa.h"
#include "Detective.h"
#include "ArbolABB.h"

#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;

int main() {

    srand(time(nullptr));

    string nombre;

    cout << "Ingrese el nombre del detective: ";
    cin >> nombre;

    Mapa mapa;

    Detective detective(nombre);

    ArbolABB arbol;

    detective.setCulpable("Miguel");

    detective.agregarSospechoso(
            Sospechoso("Carlos", "Robo"));

    detective.agregarSospechoso(
            Sospechoso("Ana", "Fraude"));

    detective.agregarSospechoso(
            Sospechoso("Miguel", "Asesinato"));

    arbol.insertar(
            Sospechoso("Carlos", "Robo"));

    arbol.insertar(
            Sospechoso("Ana", "Fraude"));

    arbol.insertar(
            Sospechoso("Miguel", "Asesinato"));

    Nodo* inicioDetective = mapa.obtenerNodoAleatorio();

    while (inicioDetective->bloqueado ||
           inicioDetective->tienePista ||
           inicioDetective->tieneTestigo) {

        inicioDetective = mapa.obtenerNodoAleatorio();
    }

    detective.setPosicion(inicioDetective);

    char movimiento;

    do {

        cout << endl;

        cout << detective.getNombre()
             << ", tu puntaje actual es: "
             << detective.getPuntaje()
             << endl;

        mapa.imprimirMapa(detective);

        cout << endl;

        cout << "W = Arriba" << endl;
        cout << "S = Abajo" << endl;
        cout << "A = Izquierda" << endl;
        cout << "D = Derecha" << endl;
        cout << "T = Ver pistas" << endl;
        cout << "I = Interrogar testigo" << endl;
        cout << "M = Mostrar sospechosos" << endl;
        cout << "B = Mostrar ABB" << endl;
        cout << "Q = Salir" << endl;

        cin >> movimiento;

        movimiento = toupper(movimiento);

        switch (movimiento) {

            case 'W':
                detective.moverArriba();
                break;

            case 'S':
                detective.moverAbajo();
                break;

            case 'A':
                detective.moverIzquierda();
                break;

            case 'D':
                detective.moverDerecha();
                break;

            case 'T':
                detective.mostrarPistas();
                break;

            case 'I':
                detective.interrogarTestigo();
                break;

            case 'M':
                detective.mostrarSospechosos();
                break;

            case 'B':
                arbol.mostrarInorder();
                break;
        }

        detective.revisarPista();

        if (detective.getPosicion()->tieneTestigo) {

            Testigo nuevo(
                    "Vi algo sospechoso cerca del callejon.");

            detective.agregarTestigo(nuevo);

            cout << endl;

            cout << "Un testigo fue agregado a la cola."
                 << endl;

            detective.getPosicion()->tieneTestigo = false;

            detective.getPosicion()->contenido = 'o';
        }

        if (detective.cantidadPistas() >= 10) {

            cout << endl;

            cout << "================================="
                 << endl;

            cout << "HAS RECOLECTADO 10 PISTAS"
                 << endl;

            cout << "ES MOMENTO DE ACUSAR"
                 << endl;

            cout << "================================="
                 << endl;

            detective.mostrarSospechosos();

            string acusacion;

            cout << endl;

            cout << "A quien acusas?: ";

            cin >> acusacion;

            if (detective.acusar(acusacion)) {

                cout << endl;

                cout << "CASO RESUELTO!" << endl;

                cout << acusacion
                     << " era el culpable."
                     << endl;

            } else {

                cout << endl;

                cout << "ACUSACION INCORRECTA."
                     << endl;

                cout << "El verdadero culpable era "
                     << detective.getCulpable()
                     << endl;
            }

            break;
        }

    } while (movimiento != 'Q');

    return 0;
}