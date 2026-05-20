cmake_minimum_required(VERSION 4.2)
project(DetectiveJueguito)

set(CMAKE_CXX_STANDARD 17)

add_executable(DetectiveJueguito main.cpp
        Nodo.cpp
        Nodo.h
        Mapa.cpp
        Mapa.h
        Detective.cpp
        Detective.h
        Juego.cpp
        Juego.h
        Pista.cpp
        Pista.h
        Testigo.cpp
        Testigo.h
        Sospechoso.cpp
        Sospechoso.h
        NodoABB.cpp
        NodoABB.h
        ArbolABB.cpp
        ArbolABB.h
        score.cpp
        score.h)
