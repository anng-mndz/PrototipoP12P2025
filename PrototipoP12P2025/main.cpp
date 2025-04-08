// main.cpp
// ========================================================
// Este archivo contiene el PROGRAMA PRINCIPAL (main).
// Aquí es donde se ejecuta toda la lógica:
// - Se crean variables
// - Se llaman funciones
// - Se repite el ciclo de votaciones si el usuario quiere
// ========================================================
#include "eleccion.h" // funciones y constantes necesarias

int main() {
    srand(time(0)); //inicializa el aleatorio

    // Crear los tres partidos
    Partido partido1("Republicano");
    Partido partido2("Democrata");
    Partido partido3("Independiente");

    char repetir;
    do {
        // Ingreso de candidatos y generación de votos
        partido1.ingresarCandidatos();
        partido1.generarVotos();

        partido2.ingresarCandidatos();
        partido2.generarVotos();

        partido3.ingresarCandidatos();
        partido3.generarVotos();

        // Mostrar resultados y cálculos
        partido1.mostrarResultados();
        partido1.calcularGanadorPerdedor();

        partido2.mostrarResultados();
        partido2.calcularGanadorPerdedor();

        partido3.mostrarResultados();
        partido3.calcularGanadorPerdedor();

        // Comparar promedios entre partidos
        float prom1 = partido1.calcularPromedio();
        float prom2 = partido2.calcularPromedio();
        float prom3 = partido3.calcularPromedio();

        float mayorProm = max(prom1, max(prom2, prom3));
        string mejorPartido = (mayorProm == prom1) ? partido1.getNombre() : (mayorProm == prom2) ? partido2.getNombre() : partido3.getNombre();

        cout << "\nEl mejor partido fue: " << mejorPartido << " con un promedio de " << mayorProm << " votos.\n";

        cout << "\nDesea realizar otra eleccion? (s/n): ";
        cin >> repetir;

    } while (repetir == 's' || repetir == 'S');

    return 0;
}
