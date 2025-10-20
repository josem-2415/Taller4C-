#include "Tablero.h"
#include "Avatar.h"
#include <iostream>

int main(){
    Tablero laberinto;
    Avatar soldado(laberinto);
    laberinto.mostrarTablero();
    return 0;
}
