cmake_minimum_required(VERSION 4.2)
project(DetectiveJueguito)

set(CMAKE_CXX_STANDARD 17)

add_executable(DetectiveJueguito main.cpp

        Nodo.cpp
        Mapa.cpp
        Detective.cpp
        Juego.cpp

        NodoABB.cpp
        ArbolABB.cpp

        NodoPista.cpp
        PilaPistas.cpp

        NodoCola.cpp
        ColaTestigos.cpp

        Sospechoso.cpp
        Testigo.cpp

        HashSospechosos.cpp

        score.cpp)
