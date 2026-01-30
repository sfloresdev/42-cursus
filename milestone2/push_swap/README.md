*Este proyecto ha sido creado como parte del currículo de 42 por [seflores].*

## Descripcion
push_swap es un proyecto de algoritmia: tienes que ordenar datos en una pila, con un conjunto limitado de instrucciones, utilizando el menor número posible de movimientos. Para tener éxito, deberás manipular varios tipos de algoritmos y elegir la solución más apropiada.

El proyecto implica el manejo de dos pilas (Stack A y Stack B) y un conjunto de instrucciones para manipularlas: (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)

## Instrucciones

### Compilación y uso

```bash
make                    # Compila el ejecutable 'push_swap'
make clean              # Elimina archivos objeto (.o)
make fclean             # Elimina objetos y el ejecutable
make re                 # Recompila desde cero
```

## Ejecución

El programa recibe como argumento una lista de números enteros (positivos o negativos) sin duplicados.

```bash
./push_swap 2 1 3 6 5 8
```

También soporta argumentos mixtos o entrecomillados (gracias al parser implementado):
```bash
./push_swap "2 1" 3 "6 5" 8
```

# Decisiones técnicas

### Arquitectura

El proyecto se estructura en componentes modulares para asegurar limpieza:

**Estructuras de Datos:** Se utilizan listas enlazadas (t_stack) en lugar de arrays. Esto permite operaciones de inserción y movimiento de nodos.

**Parser Robusto:** Implementación de un parser que normaliza la entrada usando ft_split y ft_atol. Maneja errores de sintaxis, límites de INT_MAX/INT_MIN, duplicados y libera toda la memoria en caso de error.

### Justificación del algoritmo

Se reutilizan las operaciones ya programadas para el caso de < 4, argumentos.

#### Radix Sort:
Se utiliza Radix Sort operando a nivel de bits.

**Pre-procesamiento (Indexing):** Antes de ordenar, se asigna un índice relativo (0 a N-1) a cada número (ft_index_stack). Esto permite que Radix trabaje con rangos compactos.

# Recursos 

### Documentación
- [Explicacion Radix Sort](https://es.wikipedia.org/wiki/Ordenamiento_Radix) - Pagina de Wikipedia.
- [Radix Sort explantion](https://www.codingeek.com/algorithms/radix-sort-explanation-pseudocode-and-implementation/) - Explicacion de Codingeek.

### Uso de IA
Se utilizó asistencia de IA para:

- **Refactorización:** Optimización de ft_atol y el parser.

- **Debugging:** Detección de memory leaks complejos en casos de error ("Still Reachable" al usar ft_split y exit).

- **Comprensión:** Explicación visual del funcionamiento de Radix Sort con pilas y operaciones a nivel de bit.

- **Documentación:** Formato del README.
