# Proyecto: Laberinto en C++ (Programación Orientada a Objetos)

## Descripción general

Este proyecto implementa un **laberinto 10x10** en C++ aplicando los principios de **programación orientada a objetos (POO)**.
El jugador controla un **avatar (soldado)** que se mueve dentro del laberinto en busca de la **salida X**, partiendo desde una **posición aleatoria válida**.

El juego garantiza que **siempre existe un camino posible** desde el punto inicial hasta la salida.

---

## Estructura del proyecto

```
ProyectoLaberinto
│
├── Avatar.h / Avatar.cpp      → Clase que representa al jugador (avatar)
├── Tablero.h / Tablero.cpp    → Clase que representa el laberinto
├── Game.h / Game.cpp          → Controlador principal del juego
└── main.cpp                   → Punto de entrada del programa
```

---

## Funcionamiento del juego

* El laberinto se genera con un **camino aleatorio garantizado** desde la esquina superior izquierda `[0,0]` hasta la salida `[9,9]`.
* El avatar se coloca en una celda válida aleatoria y puede moverse con:

  ```
  w → arriba
  s → abajo
  a → izquierda
  d → derecha
  q → salir
  ```
* El movimiento solo es válido si **no sale del tablero** y la celda tiene un **valor 1 (camino libre)**.
* Al llegar a la celda de la salida (`X`), el juego muestra el mensaje:

  ```
  ¡Has llegado a la salida!
  ```

---

## Clases principales

### Clase `Tablero`

* Representa el laberinto como una **matriz 10x10**.
* Cada celda puede tener valor `1` (camino) o `0` (pared).
* Genera aleatoriamente el laberinto, **garantizando un camino hasta la salida**.
* Métodos principales:

  * `mostrarTablero()`
  * `celdaValida()`
  * `getRandomCeldaValida()`

### Clase `Avatar`

* Representa al jugador.
* Atributos:

  * `x`, `y`: posición actual.
* Métodos:

  * `moverArriba()`, `moverAbajo()`, `moverIzquierda()`, `moverDerecha()`
  * Cada movimiento valida con una **referencia constante al Tablero**.

### Clase `Game`

* Coordina la ejecución del programa.
* Contiene los objetos `Tablero` y `Avatar`.
* Controla la interacción con el usuario y la detección de victoria.

---

## Relaciones entre clases

| Relación           | Tipo                        | Descripción                                          |
| ------------------ | --------------------------- | ---------------------------------------------------- |
| `Game → Avatar`    | Composición                 | `Game` contiene un objeto `Avatar`.                  |
| `Game → Tablero`   | Composición                 | `Game` contiene un objeto `Tablero`.                 |
| `Avatar ↔ Tablero` | Asociación (por referencia) | `Avatar` valida movimientos usando `const Tablero&`. |

---

## Ejecución del programa

### Compilar en terminal (Windows / Linux)

```bash
g++ -o Laberinto main.cpp Game.cpp Avatar.cpp Tablero.cpp
```

### Ejecutar

```bash
./Laberinto
```

---

## Conceptos aplicados

* Clases y objetos
* Encapsulamiento
* Relaciones entre clases (composición y asociación)
* Referencias y paso por valor
* Validación de movimiento
* Depuración y control de errores
* Manejo de versiones con Git

---

## Colaboración y control de versiones

* Usa **Git** para manejar versiones y trabajar en equipo.
* Crea ramas (`git branch`) para nuevas funciones.
* Realiza commits descriptivos, por ejemplo:

  ```
  git commit -m "Implementado camino garantizado en Tablero.cpp"
  ```
* Documenta y revisa los cambios con tu equipo antes de hacer merge.

---

## Autor

**Nombres:** *Jose Cardona, Nerie Vasquez, Sebastian Valencia, Andres Rodriguez*
**Curso:** Fundamentos de Programación Orientada a Objetos
**Institución:** Universidad del Valle
**Año:** 2025
