#include <iostream>
#include "Avatar.h"

Avatar::Avatar(int *xinicial, int *yinicial) : x(xinicial), y(yinicial) {}

//Getters para obtener la posicion actual del avatar
int Avatar::getX() const { return (x != nullptr) ? *x : 0; }
int Avatar::getY() const { return (y != nullptr) ? *y : 0; }

//Metodos para mover el avatar (validan con Tablero)
bool Avatar::moverArriba(const Tablero& t) {
    int nx = *x;
    int ny = *y - 1;
    if (t.celdaValida(nx, ny)) { *y = ny; return true; }
    return false;
}
bool Avatar::moverAbajo(const Tablero& t) {
    int nx = *x;
    int ny = *y + 1;
    if (t.celdaValida(nx, ny)) { *y = ny; return true; }
    return false;
}
bool Avatar::moverIzquierda(const Tablero& t) {
    int nx = *x - 1;
    int ny = *y;
    if (t.celdaValida(nx, ny)) { *x = nx; return true; }
    return false;
}
bool Avatar::moverDerecha(const Tablero& t) {
    int nx = *x + 1;
    int ny = *y;
    if (t.celdaValida(nx, ny)) { *x = nx; return true; }
    return false;
}