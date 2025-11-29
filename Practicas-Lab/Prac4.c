//Primer codigo 
#include <stdio.h>
#include <stdlib.h> // Necesario para malloc, calloc, realloc y free

void imprimir_arreglo(int *arr, int n, const char *nombre) {
    printf("\nValores del arreglo %s (Tamaño: %d)\n", nombre, n);
    for (int i = 0; i < n; i++) {
        printf("%s[%d] = %d\n", nombre, i, arr[i]);
    }
}

int main() {
    int n, m;
    int *arr = NULL;
    int *arr2 = NULL;
    int *temp = NULL;

    // Paso 1. Reservar memoria con malloc
    printf("\nPaso 1: malloc\n");
    printf("1. ¿Cuántos enteros quiere almacenar inicialmente (n)? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inválida. Saliendo.\n");
        return 1;
    }
    
    // 2. Reservar memoria con malloc
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        perror("Error al reservar memoria con malloc");
        return 1;
    }

    // 3. Mostrar los valores iniciales (serán basura)
    printf("\n3. Valores iniciales de arr (usando malloc - ¡Basura!):\n");
    imprimir_arreglo(arr, n, "arr");
    

    // Paso 2. Reservar memoria con calloc
    printf("\nPaso 2: calloc\n");
    // 1. Repetir la reserva, pero ahora con calloc.
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        perror("Error al reservar memoria con calloc");
        // Se necesita liberar la memoria de arr antes de salir.
        free(arr);
        return 1;
    }

    // 2. Mostrar los valores iniciales (serán 0).
    printf("\n2. Valores iniciales de arr2 (usando calloc - ¡Ceros garantizados!):\n");
    imprimir_arreglo(arr2, n, "arr2");


    // Paso 3. Llenar el arreglo
    printf("\nPaso 3: Llenar el arreglo\n");
    // 1. Pedir al usuario que ingrese n valores.
    printf("1. Ingrese %d valores enteros para arr2:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr2[%d]: ", i);
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Error de lectura. Saliendo.\n");
            // Liberar memoria antes de salir
            free(arr);
            free(arr2);
            return 1;
        }
    }
    imprimir_arreglo(arr2, n, "arr2");


    // Paso 4. Redimensionar con realloc
    printf("\nPaso 4: realloc\n");
    // 1. Preguntar al usuario un nuevo tamaño m.
    printf("1. Ingrese un nuevo tamaño (m) para el arreglo arr2: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Entrada inválida. Usando n=%d.\n", n);
        m = n;
    }
    
    // 2. Usar realloc para cambiar el tamaño de arr2.
    temp = (int *)realloc(arr2, m * sizeof(int));
    
    if (temp == NULL) {
        // realloc falló, arr2 sigue siendo válido y apuntando al bloque original.
        printf("2. Error al redimensionar la memoria con realloc. El arreglo arr2 no ha cambiado.\n");
    } else {
        // realloc fue exitoso.
        arr2 = temp; // Actualizar el puntero arr2 al nuevo bloque.
        printf("2. Memoria redimensionada correctamente a un tamaño de %d elementos.\n", m);
        
        // 3. En caso de que el arreglo sea de mayor tamaño, pedir los valores que faltan.
        if (m > n) {
            printf("\n3. Ingrese los %d valores adicionales:\n", m - n);
            for (int i = n; i < m; i++) {
                printf("arr2[%d]: ", i);
                if (scanf("%d", &arr2[i]) != 1) {
                    printf("Error de lectura. Usando 0 para el resto.\n");
                    for (int j = i; j < m; j++) {
                        arr2[j] = 0; // Inicializar los restantes para evitar basura
                    }
                    break; 
                }
            }
        }
        n = m; // Actualizar el tamaño actual del arreglo
    }

    // 5. Imprimir todos los valores
    printf("\n5. Valores finales de arr2:\n");
    imprimir_arreglo(arr2, n, "arr2");


    // Paso 5. Liberar memoria
    printf("\nPaso 5: Liberar memoria\n");
    // 1. Usar free(arr) y free(arr2).
    free(arr);
    free(arr2);

    // 2. Imprimir un mensaje confirmando la liberación.
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}



//Segundo codigo 
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente; // Puntero al siguiente nodo
} Nodo;

// Variable global (o se pasa como parámetro) para el inicio de la lista
Nodo *cabeza = NULL;

// Función para crear un nuevo nodo
Nodo *crear_nodo(int dato) {
    // 1. Reservar memoria para el nuevo nodo usando malloc
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    
    if (nuevo == NULL) {
        printf("Error: No se pudo reservar memoria.\n");
        exit(1);
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL; // Es el último nodo por defecto
    return nuevo;
}

// Función para insertar un nodo al inicio de la lista
void insertar_inicio(int dato) {
    Nodo *nuevo = crear_nodo(dato);
    
    // El puntero 'siguiente' del nuevo nodo apunta a la cabeza actual
    nuevo->siguiente = cabeza;
    
    // El nuevo nodo se convierte en la nueva cabeza de la lista
    cabeza = nuevo;
}

// Función para mostrar la lista completa
void mostrar_lista() {
    Nodo *actual = cabeza;
    printf("\nLista Simple: ");
    
    // Recorrer la lista hasta que el puntero sea NULL (fin de la lista)
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar toda la memoria de la lista
void liberar_lista() {
    Nodo *actual = cabeza;
    Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente; // Guardar la referencia al siguiente antes de liberar
        free(actual);                 // Liberar el nodo actual
        actual = siguiente;           // Moverse al siguiente nodo
    }
    cabeza = NULL; // Ver que la lista esté vacía
}

int main() {
    printf("--- Lista Enlazada Simple ---\n");
    insertar_inicio(30);
    insertar_inicio(20);
    insertar_inicio(10);
    mostrar_lista(); // Mostrara : 10 -> 20 -> 30 -> NULL

    // Liberar la memoria al final
    liberar_lista();
    printf("Memoria de la lista simple liberada.\n");

    return 0;
}