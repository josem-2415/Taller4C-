#ifndef TABLERO_H
#define TABLERO_H
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

class Tablero{
    private:
    static const int filas=10;
    static const int columnas=10;
    int tablero [filas][columnas];

    public:
    Tablero();

    void mostrarTablero()const;
    bool celdaValida(int x, int y)const;

};
#endif //TABLERO_H