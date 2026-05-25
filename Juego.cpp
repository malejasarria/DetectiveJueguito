#include "Juego.h"

#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;

Juego::Juego(string nombreDetective)
        : detective(nombreDetective) {

    srand(time(nullptr));

    inicializarSospechosos();

    inicializarDetective();

    inicializarRanking();
}

void Juego::inicializarSospechosos() {

    Sospechoso lista[8] = {

            Sospechoso(
                    "Carlos",
                    "Robo",
                    "Masculino",
                    "Negro",
                    "Morena",
                    "Alto"
            ),

            Sospechoso(
                    "Ana",
                    "Fraude",
                    "Femenino",
                    "Rubio",
                    "Blanca",
                    "Baja"
            ),

            Sospechoso(
                    "Miguel",
                    "Asesinato",
                    "Masculino",
                    "Oscuro",
                    "Triguena",
                    "Mediano"
            ),

            Sospechoso(
                    "Laura",
                    "Secuestro",
                    "Femenino",
                    "Castano",
                    "Blanca",
                    "Alta"
            ),

            Sospechoso(
                    "Pedro",
                    "Extorsion",
                    "Masculino",
                    "Pelirrojo",
                    "Morena",
                    "Bajo"
            ),

            Sospechoso(
                    "Camila",
                    "Hackeo",
                    "Femenino",
                    "Negro",
                    "Triguena",
                    "Mediana"
            ),

            Sospechoso(
                    "Jorge",
                    "Estafa",
                    "Masculino",
                    "Canoso",
                    "Blanca",
                    "Alta"
            ),

            Sospechoso(
                    "Sofia",
                    "Contrabando",
                    "Femenino",
                    "Oscuro",
                    "Morena",
                    "Baja"
            )
    };

    for (int i = 0; i < 8; i++) {

        detective.agregarSospechoso(
                lista[i]);
    }

    int culpable =
            rand() % 8;

    detective.setCulpable(
            lista[culpable]);
}

void Juego::inicializarDetective() {

    Nodo* inicio =
            mapa.obtenerNodoAleatorio();

    while (inicio->bloqueado ||
           inicio->tienePista ||
           inicio->tieneTestigo) {

        inicio =
                mapa.obtenerNodoAleatorio();
    }

    detective.setPosicion(
            inicio);
}

void Juego::inicializarRanking() {

    ranking.insertar(
            Score("Laura", 24));

    ranking.insertar(
            Score("Pedro", 35));

    ranking.insertar(
            Score("Camila", 19));
}

void Juego::mostrarMenu() {

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
    cout << "B = Mostrar ranking" << endl;
    cout << "F = Buscar detective" << endl;
    cout << "Q = Salir" << endl;
}

void Juego::procesarMovimiento(
        char movimiento) {

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

            ranking.mostrarInorder();

            break;

        case 'F': {

            string nombre;

            cout << endl;

            cout << "Nombre del detective: ";

            cin >> nombre;

            ranking.buscarDetective(
                    nombre);

            break;
        }

        case 'X': {

            char usada =
                    detective.usarPista();

            if (usada == 'P') {

                Nodo* nueva =
                        mapa.obtenerNodoAleatorio();

                while (nueva->bloqueado ||
                       nueva->tienePista ||
                       nueva->tieneTestigo) {

                    nueva =
                            mapa.obtenerNodoAleatorio();
                }

                detective.setPosicion(
                        nueva);

                cout << endl;

                cout << "Fuiste teletransportado."
                     << endl;
            }

            if (usada == 'C') {

                mapa.abrirCalles();
            }

            if (usada != 'N') {

                Nodo* nuevaPista =
                        mapa.obtenerNodoAleatorio();

                while (nuevaPista->bloqueado ||
                       nuevaPista->tienePista ||
                       nuevaPista->tieneTestigo) {

                    nuevaPista =
                            mapa.obtenerNodoAleatorio();
                }

                char tipos[4] =
                        {'H', 'C', 'T', 'P'};

                char nueva =
                        tipos[rand() % 4];

                nuevaPista->tienePista =
                        true;

                nuevaPista->tipoPista =
                        nueva;

                nuevaPista->contenido =
                        nueva;

                cout << endl;

                cout << "La pista regreso al mapa."
                     << endl;
            }

            break;
        }
    }

    detective.revisarPista();

    if (detective.getPosicion()->tieneTestigo) {

        Testigo nuevo(
                "Vi algo sospechoso cerca del callejon.");

        detective.agregarTestigo(
                nuevo);

        cout << endl;

        cout << "Has encontrado un testigo."
             << endl;

        detective.getPosicion()->tieneTestigo =
                false;

        detective.getPosicion()->contenido =
                'o';
    }
}

void Juego::faseAcusacion() {

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

        cout << "CASO RESUELTO!"
             << endl;

        cout << acusacion
             << " era el culpable."
             << endl;

        ranking.insertar(
                Score(
                        detective.getNombre(),
                        detective.getPuntaje()));

        cout << endl;

        cout << "Tu score fue agregado al ranking."
             << endl;

    } else {

        cout << endl;

        cout << "ACUSACION INCORRECTA."
             << endl;

        detective.setPuntaje(
                detective.getPuntaje() * 2);

        cout << "Tu puntaje fue duplicado."
             << endl;

        cout << "Puntaje final: "
             << detective.getPuntaje()
             << endl;

        cout << "El verdadero culpable era "
             << detective.getCulpable().getNombre()
             << endl;
    }

    cout << endl;

    ranking.mostrarInorder();
}

void Juego::iniciar() {

    char opcion;

    do {

        mostrarMenu();

        cin >> opcion;

        opcion =
                toupper(opcion);

        procesarMovimiento(
                opcion);

        if (detective.cantidadPistas()
            >= 10) {

            faseAcusacion();

            break;
        }

    } while (opcion != 'Q');
}