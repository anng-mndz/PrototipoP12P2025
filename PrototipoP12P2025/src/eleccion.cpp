// eleccion.cpp
// ========================================================
// Este archivo contiene la IMPLEMENTACIÓN de las funciones
// declaradas en "eleccion.h". Aquí se escribe cómo
// funcionan internamente.
// ========================================================

#include "eleccion.h" // Incluye las declaraciones necesarias

// --------------------------------------------------------
// Función: ingresarCandidatos
// Solicita al usuario que ingrese el nombre de cada candidato
// Los nombres se almacenan en un vector de strings.
// --------------------------------------------------------
void ingresarCandidatos(string candidatos[]) {
    cout << "Ingrese los nombres de los " << NUM_CANDIDATOS << " candidatos:" << endl;
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": ";
        cin >> candidatos[i];  // Guarda el nombre en la posición i del vector
    }
}

// --------------------------------------------------------
// Función: generarVotos
// Simula una elección generando votos aleatorios para cada
// candidato en cada ronda. Usa una matriz para almacenar
// los votos [candidato][ronda].
// --------------------------------------------------------
void generarVotos(int votos[][NUM_RONDAS]) {
    for (int r = 0; r < NUM_RONDAS; r++) { // Para cada ronda
        int votos_restantes = NUM_VOTANTES; // Total de votos disponibles

        // Se reparten votos aleatorios a los primeros candidatos
        for (int c = 0; c < NUM_CANDIDATOS - 1; c++) {
            votos[c][r] = rand() % (votos_restantes + 1); // Votos aleatorios entre 0 y votos_restantes
            votos_restantes -= votos[c][r]; // Se descuentan los votos asignados
        }

        // Al último candidato se le asigna lo que queda, para que siempre sumen 50
        votos[NUM_CANDIDATOS - 1][r] = votos_restantes;
    }
}

// --------------------------------------------------------
// Función: mostrarResultados
// Muestra una tabla con los resultados de la elección.
// Incluye partidos, candidatos, votos por ronda y total.
// También suma los votos por ronda.
// --------------------------------------------------------
void mostrarResultados(string partidos[], string candidatos[], int votos[][NUM_RONDAS]) {
    cout << "\nResultados de la eleccion:\n";
    cout << "--------------------------------------------------\n";
    cout << "Partido    | Candidato ";

    // Encabezados de rondas
    for (int r = 0; r < NUM_RONDAS; r++) {
        cout << "| Ronda " << r + 1 << " ";
    }
    cout << "| Total\n";
    cout << "--------------------------------------------------\n";

    int sumaRondas[NUM_RONDAS] = {0}; // Suma de votos por cada ronda

    for (int c = 0; c < NUM_CANDIDATOS; c++) {
        cout << partidos[c] << " | " << candidatos[c] << " \t";
        int total = 0; // Total de votos de este candidato

        for (int r = 0; r < NUM_RONDAS; r++) {
            cout << "| " << votos[c][r] << " \t"; // Mostrar votos por ronda
            total += votos[c][r];                // Sumar al total del candidato
            sumaRondas[r] += votos[c][r];        // Acumular por ronda
        }

        cout << "| " << total << "\n"; // Total de votos por candidato
    }

    // Mostrar la suma de votos por cada ronda
    cout << "--------------------------------------------------\n";
    cout << "Votos por ronda  ";
    for (int r = 0; r < NUM_RONDAS; r++) {
        cout << "| " << sumaRondas[r] << " \t";
    }
    cout << "|\n";
}

// --------------------------------------------------------
// Función: calcularGanador
// Determina el candidato con más votos (ganador) y el de
// menos votos (perdedor) sumando todas las rondas.
// --------------------------------------------------------
void calcularGanador(string candidatos[], int votos[][NUM_RONDAS]) {
    int maxVotos = 0;                            // Mayor número de votos encontrados
    int minVotos = NUM_VOTANTES * NUM_RONDAS;   // Mínimo inicializado al máximo posible
    string ganador, perdedor;

    for (int c = 0; c < NUM_CANDIDATOS; c++) {
        int total = 0; // Total de votos de este candidato

        for (int r = 0; r < NUM_RONDAS; r++) {
            total += votos[c][r]; // Suma total por candidato
        }

        if (total > maxVotos) {
            maxVotos = total;
            ganador = candidatos[c];
        }

        if (total < minVotos) {
            minVotos = total;
            perdedor = candidatos[c];
        }
    }

    cout << "\nEl ganador de la eleccion es: " << ganador << " con " << maxVotos << " votos.";
    cout << "\nEl candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.\n";
}
