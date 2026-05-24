#include "Juego.h"

#include <iostream>

using namespace std;

int main() {

        string nombre;

        cout << "================================="
             << endl;

        cout << "   DETECTIVE LINKED CASES"
             << endl;

        cout << "================================="
             << endl;

        cout << endl;

        cout << "Ingrese el nombre del detective: ";

        cin >> nombre;

        Juego juego(nombre);

        juego.iniciar();

        cout << endl;

        cout << "Gracias por jugar."
             << endl;

        return 0;
}