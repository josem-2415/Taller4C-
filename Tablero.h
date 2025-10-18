#ifndef TABLERO_H
#define TABLERO_H
#include <vector>

/*
===============================================================================
                                CRC -REGISTROPRESTACION
===============================================================================

Clase:
    RegistroPrestacion

Responsabilidades:
    - Registra el prestamo que se la hace a un usuario univalluno
    -Validar que el prestamo ya esta en el vector  y si este esta en Finalizado o en prestamo 
    

Colaboradores:
    - 

===============================================================================
*/

class Tablero {
    private:
        static const int filas = 10;
        static const int columnas = 10;
        int tablero[filas][columnas];
        
        // Método privado para generar el laberinto con camino garantizado
        void generarCaminoHaciaLaSalida(int startX, int startY);

    public:
        static const int salidaX;
        static const int salidaY;

        // Constructor por defecto que genera un laberinto con camino garantizado
        Tablero();
        
        // Métodos públicos
        void mostrarTablero(int ax = -1, int ay = -1) const;
        bool celdaValida(int x, int y) const;
        void getRandomCeldaValida(int &outX, int &outY) const;
};

#endif //TABLERO_H
