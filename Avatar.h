#ifndef AVATAR_H
#define AVATAR_H
#include "Tablero.h"

class Avatar {
    private:
        int x;
        int y;
    public:
        //Constructor para inicializar la posicion del avatar
        Avatar(int xinicial = 0, int yinicial = 0);

        //Getters para obtener la posicion actual del avatar
        int getX() const;
        int getY() const;

        //Metodos para mover el avatar: retornan true si el movimiento fue exitoso.
        //Reciben el Tablero por referencia (uso de referencias para validar movimiento).
        bool moverArriba(const Tablero& t);
        bool moverAbajo(const Tablero& t);
        bool moverIzquierda(const Tablero& t);
        bool moverDerecha(const Tablero& t);
};
#endif // AVATAR_H