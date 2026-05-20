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

    Nodo* inicioDetective = mapa.obtenerNodoAleatorio();

    detective.setPosicion(inicioDetective);

    char movimiento;

    do {



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
        }

    } while (movimiento != 'Q');

    return 0;
}