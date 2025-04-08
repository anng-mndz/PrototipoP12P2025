// eleccion.h
// ========================================================
// Este es el archivo de CABECERA (header).
// Aquí se declaran las CONSTANTES y las FUNCIONES que luego
// serán implementadas en "eleccion.cpp".
// También se colocan los #include necesarios.
// ========================================================

#ifndef ELECCION_H
#define ELECCION_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_CANDIDATOS = 5;
const int NUM_ANIOS = 4;
const int MAX_VOTOS = 1000000;

const int ANIOS[NUM_ANIOS] = {2017, 2019, 2021, 2023};

class Partido {
private:
    string nombre;
    string candidatos[NUM_CANDIDATOS];
    int votos[NUM_CANDIDATOS][NUM_ANIOS];

public:
    Partido(string _nombre);

    void ingresarCandidatos();
    void generarVotos();
    void mostrarResultados();
    float calcularPromedio();
    void calcularGanadorPerdedor();
    string getNombre();
};

#endif
