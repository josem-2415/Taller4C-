#ifndef GAME_H
#define GAME_H
#include "Tablero.h"
#include "Avatar.h"

/*
===============================================================================
                                CRC - GAME
===============================================================================

Clase:
    Game

Responsabilidades:
    - Controlar la ejecución principal del juego.
    - Coordinar la interacción entre el Avatar y el Tablero.
    - Detectar la llegada a la salida y manejar los comandos del usuario.

Colaboradores:
    - Tablero (para obtener el estado del laberinto).
    - Avatar (para controlar el movimiento del jugador).

===============================================================================
*/

class Game {
    private:
        Tablero tablero;
        Avatar avatar;
    public:
        Game();
        void run();
};
#endif // GAME_H