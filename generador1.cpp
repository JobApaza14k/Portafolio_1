//version sin objetos
#include <iostream>
#include <fstream>
using namespace std;

const int MAX_VALOR = 1000;
const int INTERVALO = 5;
const int NUM_INTERVALOS = (MAX_VALOR / INTERVALO) + 1;

int main() {
    int frecuencias[NUM_INTERVALOS] = {0};
    ifstream archivoEntrada("entrada.txt");
    ofstream archivoSalida("salida.txt");

    if (!archivoEntrada || !archivoSalida) {
        cerr << "Error al abrir archivos.\n";
        return 1;
    }

    int numero;
    while (archivoEntrada >> numero) {
        int indice = numero / INTERVALO;
        if (indice >= NUM_INTERVALOS) indice = NUM_INTERVALOS - 1;
        frecuencias[indice]++;
    }

    for (int i = 0; i < NUM_INTERVALOS; ++i) {
        int desde = i * INTERVALO;
        int hasta = desde + INTERVALO - 1;
        if (i == NUM_INTERVALOS - 1) hasta = MAX_VALOR;
        archivoSalida << "[" << desde << "-" << hasta << "] -> " << frecuencias[i] << " datos\n";
    }

    archivoEntrada.close();
    archivoSalida.close();
    return 0;
}

