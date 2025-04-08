// main.cpp
// ========================================================
// Este archivo contiene el PROGRAMA PRINCIPAL (main).
// Aquí es donde se ejecuta toda la lógica:
// - Se crean variables
// - Se llaman funciones
// - Se repite el ciclo de votaciones si el usuario quiere
// ========================================================

#include "eleccion.h" // Incluye las funciones y constantes necesarias

int main() {
    // Inicializa la semilla aleatoria para que los resultados cambien cada vez
    srand(time(0));

    // === DECLARACIÓN DE VECTORES Y MATRICES ===

    // Vector para almacenar los nombres de los candidatos
    string candidatos[NUM_CANDIDATOS];

    // Vector que guarda los nombres de los partidos (ordenados)
    string partidos[NUM_CANDIDATOS] = {
        "Partido A", "Partido B", "Partido C", "Partido D", "Partido E"
    };

    // Matriz de votos: filas = candidatos, columnas = rondas
    // votos[c][r] representa los votos del candidato c en la ronda r
    int votos[NUM_CANDIDATOS][NUM_RONDAS] = {0}; // Se inicializa con ceros

    char repetir; // Para saber si el usuario desea repetir la elección

    do {
        // === LLAMADAS A FUNCIONES ===

        ingresarCandidatos(candidatos);               // Paso 1: ingresar candidatos
        generarVotos(votos);                          // Paso 2: simular votación aleatoria
        mostrarResultados(partidos, candidatos, votos); // Paso 3: mostrar resultados
        calcularGanador(candidatos, votos);           // Paso 4: calcular y mostrar ganador/perdedor

        // Preguntar si se desea repetir la elección
        cout << "\nDesea realizar otra eleccion? (s/n): ";
        cin >> repetir;

    } while (repetir == 's' || repetir == 'S'); // Repite si el usuario dice que sí

    return 0; // Fin del programa
}
