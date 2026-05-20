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

    string nombres[8] = {

            "Carlos",
            "Ana",
            "Miguel",
            "Laura",
            "Pedro",
            "Camila",
            "Jorge",
            "Sofia"
    };

    int indiceCulpable = rand() % 8;

    detective.setCulpable(
            nombres[indiceCulpable]);

    detective.agregarSospechoso(
            Sospechoso(
                    "Carlos",
                    "Robo",
                    "Masculino",
                    "Negro",
                    "Morena",
                    "Alto"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Ana",
                    "Fraude",
                    "Femenino",
                    "Rubio",
                    "Blanca",
                    "Baja"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Miguel",
                    "Asesinato",
                    "Masculino",
                    "Oscuro",
                    "Triguena",
                    "Mediano"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Laura",
                    "Secuestro",
                    "Femenino",
                    "Castano",
                    "Blanca",
                    "Alta"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Pedro",
                    "Extorsion",
                    "Masculino",
                    "Pelirrojo",
                    "Morena",
                    "Bajo"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Camila",
                    "Hackeo",
                    "Femenino",
                    "Negro",
                    "Triguena",
                    "Mediana"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Jorge",
                    "Estafa",
                    "Masculino",
                    "Canoso",
                    "Blanca",
                    "Alta"));

    detective.agregarSospechoso(
            Sospechoso(
                    "Sofia",
                    "Contrabando",
                    "Femenino",
                    "Oscuro",
                    "Morena",
                    "Baja"));

    arbol.insertar(
            Score("Laura", 40));

    arbol.insertar(
            Score("Pedro", 15));

    arbol.insertar(
            Score("Camila", 28));

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
        cout << "X = Usar ultima pista" << endl;
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

            case 'X': {

                char tipoUsado;

                tipoUsado = detective.usarPista();

                if (tipoUsado == 'P') {

                    Nodo* nuevoLugar;

                    nuevoLugar = mapa.obtenerNodoAleatorio();

                    while (nuevoLugar->bloqueado) {

                        nuevoLugar =
                                mapa.obtenerNodoAleatorio();
                    }

                    detective.setPosicion(nuevoLugar);

                    cout << endl;

                    cout << "Fuiste teletransportado."
                         << endl;
                }

                break;
            }

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

                arbol.insertar(
                        Score(
                                detective.getNombre(),
                                detective.getPuntaje()));

                cout << endl;

                cout << "Tu score fue agregado al ABB."
                     << endl;

                cout << endl;

                arbol.mostrarInorder();

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