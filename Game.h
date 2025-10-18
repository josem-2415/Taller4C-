#ifndef GAME_H
#define GAME_H
#include "Tablero.h"
#include "Avatar.h"

class Game {
    private:
        Tablero tablero;
        Avatar avatar;
    public:
        Game();
        void run();
};
#endif // GAME_H