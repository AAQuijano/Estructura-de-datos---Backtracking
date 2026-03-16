# Estructura de Datos y Algoritmos - Práctica

Práctica de estructuras de datos y algoritmos en C++ y Python.

## Estructuras de Datos

### Lineales
- [ ] Listas enlazadas (simples, dobles, circulares)
- [ ] Pilas (Stack)
- [ ] Colas (Queue)
- [ ] Listas doblemente enlazadas

### No Lineales
- [ ] Árboles binarios
- [ ] Árboles binarios de búsqueda (BST)
- [ ] Árboles AVL
- [ ] Árboles B
- [ ] Grafos (matriz de adyacencia, lista de adyacencia)
- [ ] Montículos (Heap)
- [ ] Tablas hash

### Otras
- [ ] Conjuntos (Set)
- [ ] Mapas/Diccionarios
- [ ] Colas de prioridad

## Algoritmos

### Ordenamiento
- [ ] Burbuja (Bubble Sort)
- [ ] Inserción (Insertion Sort)
- [ ] Selección (Selection Sort)
- [ ] Quick Sort
- [ ] Merge Sort
- [ ] Heap Sort
- [ ] Counting Sort
- [ ] Radix Sort

### Búsqueda
- [ ] Búsqueda lineal
- [ ] Búsqueda binaria
- [ ] Búsqueda en profundidad (DFS)
- [ ] Búsqueda en anchura (BFS)

### Grafos
- [ ] Recorrido en profundidad (DFS)
- [ ] Recorrido en anchura (BFS)
- [ ] Dijkstra
- [ ] Bellman-Ford
- [ ] Floyd-Warshall
- [ ] Árbol mínimo expandido (Prim, Kruskal)

### Árboles
- [ ] Inorden, preorden, postorden
- [ ] Insertar, buscar, eliminar
- [ ] Altura y equilibrio

### Dinámicos
- [ ] Fibonacci (memoización)
- [ ] Subsecuencia común más larga (LCS)
- [ ] Mochila (Knapsack)
- [ ] Cambio de monedas

## Configuración del Entorno

### C++ (Windows con MSYS2)
```bash
# Compilar
g++ archivo.cpp -o archivo

# Ejecutar
./archivo
```

**Problema común**: Si `g++` no se reconoce, agregar al PATH:
```
C:\msys64\ucrt64\bin
```

### Python
```bash
python archivo.py
```

## Ejemplo: Hola Mundo

### C++
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hola Mundo" << endl;
    return 0;
}
```

### Python
```python
print("Hola Mundo")
```

## Notas

- Carpeta para C++: `cpp/`
- Carpeta para Python: `python/`
- Cada tema crear subcarpeta propia
