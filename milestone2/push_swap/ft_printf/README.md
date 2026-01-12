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

Compilar: `cc tu_archivo.c -L. -lftprintf -o programa`

## Decisiones técnicas

### Arquitectura

El proyecto se estructura en tres componentes principales:

**Formato**: Recorre la cadena carácter por carácter identificando especificadores (%).

**Gestión**: Usa `va_list`, `va_start`, `va_arg` y `va_end` de `<stdarg.h>` para manejar argumentos variables.

### Justificación del algoritmo

**Escritura directa sin buffer**: A diferencia de implementaciones que acumulan salida en un buffer, esta escribe directamente con `write()`.

**Conversión recursiva**: Para números y hexadecimales se usa recursión.

**Casos especiales**: Strings NULL imprimen "(null)", punteros NULL imprimen "0x0", y números negativos se manejan con recursión para evitar overflow con INT_MIN.

## Recursos

### Documentación
- [Manual de printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Referencia oficial
- [understanding ft_printf](https://www.youtube.com/watch?v=Hb2m7htiKWM) - Explicación del proyecto

### Uso de IA

Se utilizó para:
- **Investigación**: Aclarar conceptos sobre `va_list`.
- **Debugging**: Identificar errores en conversión hexadecimal y manejo de punteros nulos
- **Optimización**: Sugerencias para reducir llamadas a write y simplificar condicionales
- **Documentación**: Formato del README.
