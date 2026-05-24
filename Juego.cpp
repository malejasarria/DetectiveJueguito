#include "Juego.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Juego::Juego(
        string nombreDetective)

    : detective(nombreDetective) {

    terminado = false;

    srand(time(nullptr));

    detective.setPosicion(
            mapa.obtenerInicio());

    inicializarSospechosos();

    generarCulpable();
}

void Juego::inicializarSospechosos() {

    Sospechoso s1(
            "Carlos",
            "Robo",
            "Hombre",
            "Negro",
            "Triguena",
            "Alta");

    Sospechoso s2(
            "Laura",
            "Fraude",
            "Mujer",
            "Rubio",
            "Blanca",
            "Baja");

    Sospechoso s3(
            "Miguel",
            "Secuestro",
            "Hombre",
            "Castano",
            "Morena",
            "Media");

    Sospechoso s4(
            "Camila",
            "Hackeo",
            "Mujer",
            "Negro",
            "Blanca",
            "Alta");

    Sospechoso s5(
            "Pedro",
            "Extorsion",
            "Hombre",
            "Pelirrojo",
            "Triguena",
            "Baja");

    Sospechoso s6(
            "Sofia",
            "Contrabando",
            "Mujer",
            "Castano",
            "Morena",
            "Media");

    Sospechoso s7(
            "Jorge",
            "Estafa",
            "Hombre",
            "Rubio",
            "Blanca",
            "Alta");

    Sospechoso s8(
            "Ana",
            "Lavado",
            "Mujer",
            "Negro",
            "Triguena",
            "Baja");

    sospechosos.insertar(s1);
    sospechosos.insertar(s2);
    sospechosos.insertar(s3);
    sospechosos.insertar(s4);
    sospechosos.insertar(s5);
    sospechosos.insertar(s6);
    sospechosos.insertar(s7);
    sospechosos.insertar(s8);

    detective.agregarSospechoso(s1);
    detective.agregarSospechoso(s2);
    detective.agregarSospechoso(s3);
    detective.agregarSospechoso(s4);
    detective.agregarSospechoso(s5);
    detective.agregarSospechoso(s6);
    detective.agregarSospechoso(s7);
    detective.agregarSospechoso(s8);
}

void Juego::generarCulpable() {

    string nombres[8] = {
            "Carlos",
            "Laura",
            "Miguel",
            "Camila",
            "Pedro",
            "Sofia",
            "Jorge",
            "Ana"
    };

    string nombreElegido =
            nombres[rand() % 8];

    Sospechoso* culpable =
            sospechosos.buscar(
                    nombreElegido);

    if (culpable != nullptr) {

        detective.setCulpable(
                *culpable);
    }
}

void Juego::mostrarControles() {

    cout << endl;

    cout << "W = Arriba" << endl;

    cout << "S = Abajo" << endl;

    cout << "A = Izquierda" << endl;

    cout << "D = Derecha" << endl;

    cout << "T = Ver pistas" << endl;

    cout << "X = Usar ultima pista"
         << endl;

    cout << "I = Interrogar testigo"
         << endl;

    cout << "M = Mostrar sospechosos"
         << endl;

    cout << "B = Mostrar ranking"
         << endl;

    cout << "Q = Salir"
         << endl;
}

void Juego::procesarMovimiento(
        char opcion) {

    switch (opcion) {

        case 'w':

            detective.moverArriba();

            break;

        case 's':

            detective.moverAbajo();

            break;

        case 'a':

            detective.moverIzquierda();

            break;

        case 'd':

            detective.moverDerecha();

            break;
    }
}

void Juego::revisarCasilla() {

    Nodo* actual =
            detective.getPosicion();

    detective.revisarPista();

    if (actual->tieneTestigo) {

        Testigo nuevo(
                "Vi al sospechoso cerca del crimen.");

        detective.agregarTestigo(
                nuevo);

        cout << endl;

        cout << "Has encontrado un testigo."
             << endl;

        actual->tieneTestigo =
                false;

        actual->contenido =
                'o';
    }
}

void Juego::iniciar() {

    char opcion;

    while (!terminado) {

        cout << endl;

        cout << detective.getNombre()
             << ", tu puntaje actual es: "
             << detective.getPuntaje()
             << endl;

        mapa.imprimirMapa(
                detective);

        mostrarControles();

        cin >> opcion;

        procesarMovimiento(opcion);

        revisarCasilla();

        switch (opcion) {

            case 't':

                detective.mostrarPistas();

                break;

            case 'x': {

                char usada =
                        detective.usarPista();

                if (usada == 'P') {

                    mapa.abrirCalles();
                }

                break;
            }

            case 'i':

                detective.interrogarTestigo();

                break;

            case 'm':

                detective.mostrarSospechosos();

                break;

            case 'b':

                ranking.mostrarInorder();

                break;

            case 'q':

                terminado = true;

                break;
        }
    }

    Score resultado(
            detective.getNombre(),
            detective.getPuntaje());

    ranking.insertar(resultado);

    cout << endl;

    cout << "Juego terminado."
         << endl;

    cout << "Puntaje final: "
         << detective.getPuntaje()
         << endl;
}