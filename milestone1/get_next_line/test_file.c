#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void test_file(const char* filename) {
    int fd;
    char *line;
    int count = 0;
    
    printf("\n=== Probando: %s ===\n", filename);
    
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("❌ No se pudo abrir %s\n", filename);
        return;
    }
    
    while ((line = get_next_line(fd)) != NULL) {
        count++;
        printf("Línea %d: [", count);
        
        // Mostrar caracteres especiales
        for (int i = 0; line[i]; i++) {
            if (line[i] == '\n')
                printf("\\n");
            else if (line[i] == '\t')
                printf("\\t");
            else if (line[i] == ' ')
                printf("·");  // Punto medio para espacios
            else
                printf("%c", line[i]);
        }
        printf("]\n");
        
        free(line);
    }
    
    printf("✅ Total líneas leídas: %d\n", count);
    close(fd);
}

int main(void) {
    printf("🧪 INICIANDO PRUEBAS DE ROBUSTEZ GET_NEXT_LINE\n");
    printf("===============================================\n");
    
    // Prueba todos tus archivos
    test_file("test_empty.txt");
    test_file("test_only_newlines.txt");
    test_file("test_no_final_newline.txt");
    test_file("test_mixed.txt");
    test_file("test.txt");
    
    printf("\n=== CASOS DE ERROR ===\n");
    
    // FD inválido
    printf("Probando FD -1: ");
    char *line = get_next_line(-1);
    printf("%s\n", line ? "❌ FALLO - debería ser NULL" : "✅ OK (NULL)");
    
    printf("Probando FD 999: ");
    line = get_next_line(999);
    printf("%s\n", line ? "❌ FALLO - debería ser NULL" : "✅ OK (NULL)");
    
    // Archivo que no existe
    printf("Probando archivo inexistente: ");
    int bad_fd = open("no_existe.txt", O_RDONLY);
    if (bad_fd < 0) {
        printf("✅ OK - open falló correctamente\n");
    } else {
        line = get_next_line(bad_fd);
        printf("%s\n", line ? "❌ FALLO" : "✅ OK");
        close(bad_fd);
    }
    
    printf("\n🏁 PRUEBAS COMPLETADAS\n");
    printf("===============================================\n");
    printf("Si no hay crashes ni memory leaks, ¡tu función es robusta!\n");
    
    return 0;
}