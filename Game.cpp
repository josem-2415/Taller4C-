#include <iostream>
#include <cstdlib>
#include <limits>
#include "Game.h"

using namespace std;

Game::Game() : tablero(), avatar(0,0) {
    int sx, sy;
    tablero.getRandomCeldaValida(sx, sy);
    avatar = Avatar(sx, sy);
}

void Game::run() {
    char cmd;
    while (true) {
        system("cls"); // Windows
        cout << "Movimientos: w(arriba) s(abajo) a(izq) d(der), q para salir\n";
        tablero.mostrarTablero(avatar.getX(), avatar.getY());
        if (avatar.getX() == Tablero::salidaX && avatar.getY() == Tablero::salidaY) {
            cout << "¡Has llegado a la salida!\n";
            break;
        }
        cout << "Ingresa comando: ";
        if (!(cin >> cmd)) break;
        bool moved = false;
        switch(cmd) {
            case 'w': case 'W': moved = avatar.moverArriba(tablero); break;
            case 's': case 'S': moved = avatar.moverAbajo(tablero); break;
            case 'a': case 'A': moved = avatar.moverIzquierda(tablero); break;
            case 'd': case 'D': moved = avatar.moverDerecha(tablero); break;
            case 'q': case 'Q': return;
            default: cout << "Comando invalido\n"; break;
        }
        if (!moved) {
            cout << "Movimiento invalido (pared o fuera del tablero). Presiona Enter para continuar.";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
        }
    }
}