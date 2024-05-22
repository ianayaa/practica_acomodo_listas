#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Videojuego {
    string nombre;
    float calificacion;
    float precio;
};

void mostrarVideojuegos(const vector<Videojuego>& videojuegos) {
    cout << "-------------------------------------------------------" << endl;
    cout << "| Nombre                | Calificación | Precio       |" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (const Videojuego& videojuego : videojuegos) {
        cout << "| " << setw(20) << left << videojuego.nombre << " | "
             << setw(12) << right << videojuego.calificacion << " | "
             << setw(12) << right << videojuego.precio << " |" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

void ordenarPorCalificacion(vector<Videojuego>& videojuegos) {
    bool ordenado = false;
    while (!ordenado) {
        ordenado = true;
        for (int i = 0; i < videojuegos.size() - 1; ++i) {
            if (videojuegos[i].calificacion > videojuegos[i + 1].calificacion) {
                swap(videojuegos[i], videojuegos[i + 1]);
                ordenado = false;
            }
        }
    }
}

void ordenarPorPrecio(vector<Videojuego>& videojuegos) {
    for (int i = 0; i < videojuegos.size(); ++i) {
        int indiceMinimo = i;
        for (int j = i + 1; j < videojuegos.size(); ++j) {
            if (videojuegos[j].precio < videojuegos[indiceMinimo].precio) {
                indiceMinimo = j;
            }
        }
        swap(videojuegos[i], videojuegos[indiceMinimo]);
    }
}

int main() {
    vector<Videojuego> videojuegos;

    // Ingresar videojuegos
    int cantidadVideojuegos;
    cout << "Ingrese la cantidad de videojuegos: ";
    cin >> cantidadVideojuegos;
    for (int i = 0; i < cantidadVideojuegos; ++i) {
        Videojuego videojuego;
        cout << "Ingrese el nombre del videojuego " << i + 1 << ": ";
        cin.ignore(); // Ignorar el caracter de nueva linea
        getline(cin, videojuego.nombre);
        cout << "Ingrese la calificación del videojuego: ";
        cin >> videojuego.calificacion;
        cout << "Ingrese el precio del videojuego: ";
        cin >> videojuego.precio;
        videojuegos.push_back(videojuego);
    }

    // Mostrar lista de videojuegos
    mostrarVideojuegos(videojuegos);

    // Ordenar por calificación
    ordenarPorCalificacion(videojuegos);
    cout << "\nVideojuegos ordenados por calificación:" << endl;
    mostrarVideojuegos(videojuegos);

    // Ordenar por precio
    ordenarPorPrecio(videojuegos);
    cout << "\nVideojuegos ordenados por precio:" << endl;
    mostrarVideojuegos(videojuegos);

    return 0;
}

