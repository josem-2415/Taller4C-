# Proyecto: Laberinto en C++ (Programación Orientada a Objetos)

## Descripción general

Este proyecto implementa un **laberinto 10x10** en C++ aplicando los principios de **programación orientada a objetos (POO)**.
El jugador controla un **avatar (soldado)** que se mueve dentro del laberinto en busca de la **salida (X)**, partiendo desde una **posición aleatoria válida**.

El sistema garantiza que **siempre exista un camino posible** desde el punto inicial hasta la salida, generando un entorno jugable en cada ejecución.

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
* El avatar se coloca en una **celda válida aleatoria** y puede moverse con:

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
* **Métodos principales:**

  * `mostrarTablero()`
  * `celdaValida()`
  * `getRandomCeldaValida()`

### Clase `Avatar`

* Representa al jugador.
* **Atributos:**

  * `x`, `y`: posición actual.
* **Métodos:**

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
* Uso de referencias en métodos
* Validación de movimiento y control de flujo
* Depuración y manejo de errores
* Control de versiones con Git y GitHub

---

## Colaboración y control de versiones

* Uso de **Git** para manejar versiones y trabajar en equipo.
* Creación de ramas (`git branch`) para desarrollo paralelo.
* Commits descriptivos, por ejemplo:

  ```bash
  git commit -m "Implementado camino garantizado en Tablero.cpp"
  ```
* Documentación y revisión colaborativa antes de hacer *merge*.

---

## Autores

**Nombres:** Jose Cardona, Nerie Vasquez, Sebastian Valencia, Andres Rodriguez
**Curso:** Fundamentos de Programación Orientada a Objetos
**Institución:** Universidad del Valle
**Año:** 2025
