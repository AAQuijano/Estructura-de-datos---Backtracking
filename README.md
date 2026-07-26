# Proyecto #3 — Estructura de Datos y Algoritmos

## Objetivo

Resolver los enunciados del [Proyecto3_Enunciados.pdf](Enunciados/Proyecto3_Enunciados.pdf) implementando un **grafo dirigido** de las provincias de Panamá con conexiones aéreas, en **C++** y **Python**.

## Estructura del proyecto

```
Proyecto#3 - Estructura de datos/
├── Enunciados/
│   └── Proyecto3_Enunciados.pdf      # Enunciados a resolver
├── cpp/
│   ├── Old_version/
│   │   └── Proyecto#3_Enunciado#1.cpp  # Enunciado #1 (monolítico)
│   └── New_Version/                     # Refactorización en progreso
│       ├── Red.h                        # Clase Grafo
│       ├── Datos.h                      # Datos de provincias
│       └── Problema1.cpp                # Programa principal
├── python/
│   └── main.py                          # Esqueleto inicial
├── .gitignore
└── README.md
```

## Estado del proyecto

| Enunciado | C++                          | Python       |
| --------- | ---------------------------- | ------------ |
| #1        | ❌ Pendiente                 | ❌ Pendiente |
| #2         | ❌ Pendiente                | ❌ Pendiente |

## Implementación actual (C++)

Solo existe una versión inicial del **Enunciado #1**:

- **Monolítica** (`Old_version/Proyecto#3_Enunciado#1.cpp`) — 1330 líneas en un solo archivo, con menú interactivo, lista de adyacencia, matrices de costo/distancia, DFS y backtracking para búsqueda de rutas.

## Modelo de datos — Grafo de provincias

### Nodos (8 provincias)

Panama, Herrera, Colon, Cocle, LosSantos, Chiriqui, Veraguas, BocasDelToro

### Aristas dirigidas (11 conexiones)

| Origen → Destino     | Km     |
| --------------------- | ------ |
| Cocle → Veraguas     | 2414   |
| Veraguas → LosSantos | 3218.6 |
| Veraguas → Chiriqui  | 2414   |
| Veraguas → Herrera   | 2414   |
| LosSantos → Chiriqui | 3218.6 |
| Panama → Colon       | 2414   |
| Panama → Veraguas    | 3862.4 |
| Panama → Cocle       | 2092.2 |
| Colon → BocasDelToro | 3218.6 |
| Colon → Cocle        | 1609.4 |
| Colon → Chiriqui     | 3701.5 |

Cada arista almacena distancia (km), tiempo (min) y costo.

### Algoritmos

- **DFS** — recorrido en profundidad
- **Backtracking** — búsqueda de rutas origen→destino filtrando por km, tiempo o costo

## Compilación (C++)

```bash
g++ Old_version/Proyecto#3_Enunciado#1.cpp -o enunciado1.exe
```

## Ejecución (Python)

```bash
python python/main.py
```
