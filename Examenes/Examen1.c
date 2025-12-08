#include <stdio.h>
#include <stdlib.h> // Necesaria para malloc, realloc, y free

// Función para calcular y retornar el promedio
float calcular_promedio(float *calificaciones, int n) {
    if (n == 0) {
        return 0.0f;
    }
    float suma = 0.0f;
    for (int i = 0; i < n; i++) {
        suma += calificaciones[i];
    }
    return suma / n;
}

// Función principal
int main() {
    int n = 0; // Tamaño actual del arreglo (número de estudiantes)
    float *calificaciones = NULL; // Puntero al arreglo de calificaciones
    int nuevos_estudiantes = 0;

    // 1. Pedir al usuario cuántos estudiantes desea registrar inicialmente.
    printf("¿Cuántos estudiantes deseas registrar? ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Error: Ingrese una cantidad válida y positiva.\n");
        return 1; // Terminar con error
    }

    // 2. Reservar memoria dinámicamente con malloc()
    // Se reserva memoria para n elementos de tipo float.
    calificaciones = (float *)malloc(n * sizeof(float));

    // Verificar si malloc() devuelve NULL (error de asignación de memoria).
    if (calificaciones == NULL) {
        printf("Error: No se pudo asignar la memoria inicial con malloc().\n");
        return 1; // Terminar el programa si falla la asignación
    }

    // 3. Capturar las calificaciones iniciales
    printf("\n Ingreso de calificaciones iniciales \n");
    for (int i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        if (scanf("%f", &calificaciones[i]) != 1) {
            printf("Error: Ingrese un valor numérico válido.\n");
            // Liberar la memoria antes de salir por error
            free(calificaciones);
            return 1; 
        }
    }

    // 4. Mostrar todas las calificaciones y el promedio inicial.
    float promedio_inicial = calcular_promedio(calificaciones, n);
    printf("Promedio inicial: %.2f\n", promedio_inicial);

    // 5. Preguntar al usuario si desea agregar más estudiantes
    printf("\n¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    if (scanf("%d", &nuevos_estudiantes) != 1 || nuevos_estudiantes < 0) {
        printf("Error: Ingrese una cantidad válida.\n");
        // Liberar la memoria antes de salir por error
        free(calificaciones);
        return 1;
    }

    // Si el usuario quiere agregar más estudiantes (nuevos_estudiantes > 0)
    if (nuevos_estudiantes > 0) {
        int nuevo_tamano = n + nuevos_estudiantes;
        
        // Usar realloc() para ampliar el tamaño del arreglo.
        // Se intenta redimensionar a 'nuevo_tamano' elementos de tipo float.
        float *temp_calificaciones = (float *)realloc(calificaciones, nuevo_tamano * sizeof(float));

        // Verificar si realloc() devuelve NULL (error de asignación de memoria).
        if (temp_calificaciones == NULL) {
            printf("Error: No se pudo ampliar la memoria con realloc().\n");
            // La memoria original (calificaciones) sigue siendo válida y debe liberarse.
            free(calificaciones); 
            return 1; // Terminar con error
        }

        // Si realloc() tuvo éxito, actualizamos el puntero y el tamaño.
        calificaciones = temp_calificaciones;
        
        // 6. Capturar las nuevas calificaciones
        printf("\n Ingreso de nuevas calificaciones \n");
        for (int i = n; i < nuevo_tamano; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            if (scanf("%f", &calificaciones[i]) != 1) {
                printf("Error: Ingrese un valor numérico válido.\n");
                // Liberar la memoria antes de salir por error
                free(calificaciones);
                return 1; 
            }
        }
        
        // Actualizar el tamaño total de la lista de estudiantes
        n = nuevo_tamano;
    }

    // 6. Recalcular y mostrar el promedio total
    float promedio_final = calcular_promedio(calificaciones, n);

    // Mostrar todas las calificaciones registradas
    printf("\n Calificaciones registradas \n");
    for (int i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    printf("Promedio general: %.2f\n", promedio_final);

    // 7. Liberar la memoria utilizada al final del programa con free().
    if (calificaciones != NULL) {
        free(calificaciones);
        calificaciones = NULL; // Buena práctica: evita punteros 'colgantes'
        printf("Memoria liberada correctamente.\n");
    }

    return 0; // Finalización exitosa
}