#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"

Tablero::Tablero(){
    srand(time(0));
    for(int i=0;i<filas;i++){
        for(int j=0; j<columnas;j++){
            tablero [i][j]=(rand()%2);//muetra un numero del 0 al 1 en cada espacio de la matriz
        }
    }

}

void Tablero::mostrarTablero()const{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            std::cout<<tablero[i] [j]<<"\t";
        }
       std::cout<<std::endl; 
    }
}
bool Tablero::celdaValida(int x, int y)const{
    return (x >= 0 && x < filas && y >= 0 && y < columnas && tablero[x][y] == 1);
};