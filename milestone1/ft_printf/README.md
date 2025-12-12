*Este proyecto ha sido creado como parte del currículo de 42 por [seflores].*

## Descripción

ft_printf es una reimplementación de la función `printf()` de la biblioteca estándar de C. El objetivo es comprender el funcionamiento de las funciones variádicas (N argumentos) y practicar el manejo de conversiones de tipos y formato de salida. El proyecto implementa estas conversiones: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` y `%%`.

## Instrucciones

### Compilación y uso

```bash
make                    # Compila la biblioteca
make clean              # Elimina archivos objeto
make fclean             # Elimina objetos y biblioteca
make re                 # Recompila desde cero
```

### Integración en tu proyecto

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, número: %d, hex: %x\n", "mundo", 42, 255);
    return 0;
}
```

Compilar: `cc *flags* tu_archivo.c -L. -lftprintf -o programa`

## Decisiones técnicas

### Arquitectura

El proyecto se estructura en tres componentes principales:

**Formato**: Recorre la cadena carácter por carácter identificando especificadores (%).

**Gestión**: Usa `va_list`, `va_start`, `va_arg` y `va_end` de `<stdarg.h>` para manejar argumentos variables.

**Funciones**: Cada conversor tiene su función individual (`ft_print_char`, `ft_print_str`, `ft_print_ptr`, `ft_print_nbr`, `ft_print_unsigned`, `ft_print_hex`), siguiendo el principio de responsabilidad única para mayor modularidad y testabilidad.

### Justificación del algoritmo

**Parser secuencial simple**: Se eligió por eficiencia O(n), simplicidad de código y bajo uso de memoria. No requiere estructuras auxiliares complejas.

**Escritura directa sin buffer**: A diferencia de implementaciones que acumulan salida en un buffer, esta escribe directamente con `write()`. Sacrifica un poco de rendimiento a cambio de no tener límites de tamaño y menor complejidad en gestión de memoria.

**Conversión recursiva**: Para números y hexadecimales se usa recursión, evitando buffers temporales y simplificando la lógica de conversión.

**Casos especiales**: Strings NULL imprimen "(null)", punteros NULL imprimen "0x0", y números negativos se manejan con recursión para evitar overflow con INT_MIN.

## Recursos

### Documentación
- [Manual de printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Referencia oficial
- [understanding ft_printf](https://www.youtube.com/watch?v=Hb2m7htiKWM) - Explicación del proyecto

### Uso de IA

**Claude (Anthropic)** se utilizó para:
- **Investigación**: Aclarar conceptos sobre `va_list`.
- **Debugging**: Identificar errores en conversión hexadecimal y manejo de punteros nulos
- **Optimización**: Sugerencias para reducir llamadas a write y simplificar condicionales
- **Documentación**: Formato del README.

Todo el código fue escrito, comprendido y testeado personalmente. La IA se usó como herramienta de apoyo, no como generador automático.