#include "Mapa.h"
#include "Detective.h"

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

    detective.agregarSospechoso(
            Sospechoso("Carlos", "Robo"));

    detective.agregarSospechoso(
            Sospechoso("Ana", "Fraude"));

    detective.agregarSospechoso(
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

    } while (movimiento != 'Q');

    return 0;
}