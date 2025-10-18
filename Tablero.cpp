#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"

using namespace std;

const int Tablero::salidaX = Tablero::filas - 1;
const int Tablero::salidaY = Tablero::columnas - 1;

Tablero::Tablero(){
    srand((unsigned)time(0));
    for(int i=0;i<filas;i++){
        for(int j=0; j<columnas;j++){
            tablero[i][j]=(rand()%2);// 0 o 1
        }
    }
    // Asegurar que la salida sea transitable
    tablero[salidaX][salidaY] = 1;
}

void Tablero::mostrarTablero(int ax, int ay)const{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if (i==ay && j==ax) { // avatar (note: avatar uses x=col, y=row)
                std::cout << 'A';
            } else if (i==salidaY && j==salidaX) {
                std::cout << 'X'; // salida
            } else {
                std::cout << (tablero[j][i] == 1 ? '.' : '#');
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
