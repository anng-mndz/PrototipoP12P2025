// eleccion.cpp
// ========================================================
// LUIS ANGEL MENDEZ FUENTES 9959-24-6845
// SEGUNDO PARCIAL PRACTICO SERIE IV
// Este archivo contiene la IMPLEMENTACI�N de las funciones
// declaradas en "eleccion.h". Aqu� se escribe c�mo
// funcionan internamente.
// ========================================================
#include "eleccion.h" //para las constantes necesarias
Partido::Partido(string _nombre) {
    nombre = _nombre;
    // Inicializa los votos en cero
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        for (int j = 0; j < NUM_ANIOS; j++) {
            votos[i][j] = 0;
        }
    }
}
// --------------------------------------------------------
// Funci�n: ingresarCandidatos
// Solicita al usuario que ingrese el nombre de cada candidato
// Los nombres se almacenan en un vector de strings.
// --------------------------------------------------------
void Partido::ingresarCandidatos() {
    cout << "Ingrese los nombres de los " << NUM_CANDIDATOS << " candidatos para el partido " << nombre << ":\n";
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": ";
        cin >> candidatos[i];
    }
}
// --------------------------------------------------------
// Funci�n: generarVotos
// Simula una elecci�n generando votos aleatorios para cada
// candidato en cada ronda. Usa una matriz para almacenar
// los votos [candidato][ronda].
// --------------------------------------------------------
void Partido::generarVotos() {
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        for (int j = 0; j < NUM_ANIOS; j++) {
            votos[i][j] = rand() % (MAX_VOTOS + 1);
        }
    }
}
// --------------------------------------------------------
// Funci�n: mostrarResultados
// Muestra una tabla con los resultados de la elecci�n.
// Incluye partidos, candidatos, votos por ronda y total.
// Tambi�n suma los votos por ronda.
// --------------------------------------------------------
void Partido::mostrarResultados() {
    cout << "\nResultados del partido: " << nombre << "\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Candidato\t";
    for (int j = 0; j < NUM_ANIOS; j++) {
        cout << ANIOS[j] << "\t";
    }
    cout << "Total\n";

    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << candidatos[i] << "\t";
        int total = 0;
        for (int j = 0; j < NUM_ANIOS; j++) {
            cout << votos[i][j] << "\t";
            total += votos[i][j];
        }
        cout << total << endl;
    }
    cout << "-------------------------------------------------------------\n";
}

float Partido::calcularPromedio() {
    int sumaTotal = 0;
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        for (int j = 0; j < NUM_ANIOS; j++) {
            sumaTotal += votos[i][j];
        }
    }
    return (float)sumaTotal / (NUM_CANDIDATOS * NUM_ANIOS);
}
// --------------------------------------------------------
// Funci�n: calcularGanador
// Determina el candidato con m�s votos (ganador) y el de
// menos votos (perdedor) sumando todas las rondas.
// --------------------------------------------------------
void Partido::calcularGanadorPerdedor() {
    int maxVotos = 0, minVotos = MAX_VOTOS * NUM_ANIOS;
    string ganador, perdedor;

    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        int total = 0;
        for (int j = 0; j < NUM_ANIOS; j++) {
            total += votos[i][j];
        }
        if (total > maxVotos) {
            maxVotos = total;
            ganador = candidatos[i];
        }
        if (total < minVotos) {
            minVotos = total;
            perdedor = candidatos[i];
        }
    }
    cout << "\nGanador del partido " << nombre << ": " << ganador << " con " << maxVotos << " votos." << endl;
    cout << "Perdedor del partido " << nombre << ": " << perdedor << " con " << minVotos << " votos." << endl;
}

string Partido::getNombre() {
    return nombre;
}
