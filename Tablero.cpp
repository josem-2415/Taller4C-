#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"

using namespace std;

const int Tablero::salidaX = Tablero::filas - 1;
const int Tablero::salidaY = Tablero::columnas - 1;

Tablero::Tablero(){                    //Inicializa cada objeto como una matriz de 0 y 1 ubicados en posiciones aleatorias
    srand(time(0));                    //crea números aleatorios usando como semilla 0
    for(int i=0;i<filas;i++){
        for(int j=0; j<columnas;j++){  //Bucle anidado para rellenar la matriz tablero
            int numero = rand() % 100; // 0 a 99
            if (numero < 15) {         // 15% de probabilidad
                tablero[i][j] = 1;
            } else {
                tablero[i][j] = 0;
            } //muetra un 0 o un 1 en cada espacio de la matriz
        }
    }
    for (int i = 0; i < filas; i++) { //Crea un camino posible en zigzag
        if (i % 2 == 0) { // fila par
            for (int j = 0; j < columnas; j++)
            tablero[i][j] = 1;
        }
        else { // fila impar
            tablero[i][columnas - 1] = 1;
        }
    }

}

void Tablero::mostrarTablero(int ax, int ay)const{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (i==ay && j==ax) { // avatar (note: avatar uses x=col, y=row)
                std::cout << 'A';
            } else if (i==salidaY && j==salidaX) {
                std::cout << 'X'; // salida
            } else {
                std::cout << (tablero[j][i] == 1 ? '1' : '0');
            }
            std::cout << "\t";
        }
       std::cout<<std::endl;
    }
}
bool Tablero::celdaValida(int x, int y)const{
    return (x >= 0 && x < filas && y >= 0 && y < columnas && tablero[x][y] == 1);
}

void Tablero::getRandomCeldaValida(int &outX, int &outY) const {
    // Busca aleatoriamente hasta encontrar una celda con valor 1 (no la salida necesariamente)
    do {
        outX = rand() % filas;
        outY = rand() % columnas;
    } while(!celdaValida(outX, outY));
}

