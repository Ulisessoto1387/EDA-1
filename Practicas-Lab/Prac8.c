//Primer codigo 
#include <stdio.h>
#include <stdlib.h>

// Paso A1. Creación de la estructura
struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};


// FUNCIONES BÁSICAS
void insertarInicio(struct Nodo **inicio, int valor) {
    // 1. Crear nuevo nodo
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo reservar memoria para el nodo.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    
    // 2. Conectar el nuevo nodo al inicio
    // Paso A2. Ejemplo de inserción al inicio
    nuevo->siguiente = *inicio;
    
    // 3. Si la lista no estaba vacía, el nodo anterior del actual *inicio debe ser el nuevo
    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }
    
    // 4. Actualizar el puntero de inicio de la lista
    *inicio = nuevo;
    printf("-> Insertado %d al inicio.\n", valor);
}

void insertarFinal(struct Nodo **inicio, int valor) {
    // 1. Crear nuevo nodo
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo reservar memoria para el nodo.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    
    // Caso 1: La lista está vacía
    if (*inicio == NULL) {
        *inicio = nuevo;
        printf("-> Insertado %d al final (lista vacía).\n", valor);
        return;
    }

    // Caso 2: Recorrer hasta el final
    struct Nodo *actual = *inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    
    // 3. Conectar el nuevo nodo
    actual->siguiente = nuevo;
    nuevo->anterior = actual;
    printf("-> Insertado %d al final.\n", valor);
}

// o recorrerAdelante(struct Nodo *inicio)
void recorrerAdelante(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("\nRecorrido Adelante: ");
    struct Nodo *actual = inicio;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    
    // 1. Ir al último nodo
    struct Nodo *actual = inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    
    // 2. Recorrer hacia atrás
    printf("Recorrido Atrás: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("La lista está vacía, no se puede eliminar %d.\n", valor);
        return;
    }
    
    struct Nodo *actual = *inicio;

    // 1. Buscar el nodo a eliminar
    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    // Si no se encuentra el valor
    if (actual == NULL) {
        printf("El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    // Paso A4. Considerar tres casos:
    // Caso 1: El nodo está al inicio.
    if (actual->anterior == NULL) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL; // Desconectar el 'anterior' del nuevo inicio
        }
    } 
    // Caso 2: El nodo está al final.
    else if (actual->siguiente == NULL) {
        actual->anterior->siguiente = NULL; // El penúltimo ahora apunta a NULL
    }
    // Caso 3: El nodo está en medio.
    else {
        actual->anterior->siguiente = actual->siguiente;
        actual->siguiente->anterior = actual->anterior;
    }

    // 4. Libera la memoria del nodo eliminado.
    printf("-> Eliminado el valor %d.\n", valor);
    free(actual);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    struct Nodo *siguiente;
    
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    // Paso A5. Mensaje de liberación
    printf("\nMemoria liberada correctamente.\n");
}

// FUNCIÓN PRINCIPAL (PRUEBA)
int main() {
    // Paso A1. 1. Declara un puntero *inicio inicializado en NULL.
    struct Nodo *inicio = NULL;
    int num_valores, valor;

    //Paso A2. Inserción

    // 1. Pide al usuario cuántos valores desea insertar al inicio
    printf(" Fase de Inserción al Inicio \n");
    printf("¿Cuántos valores desea insertar al inicio.");
    if (scanf("%d", &num_valores) != 1 || num_valores < 0) {
         printf("Entrada inválida. Terminando el programa.\n");
         liberar(inicio);
         return 1;
    }

    // 2. Inserta los nodos al inicio
    for (int i = 0; i < num_valores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
             printf("Entrada inválida. Terminando el programa.\n");
             liberar(inicio);
             return 1;
        }
        insertarInicio(&inicio, valor);
    }
    
    // 2. Muestra la lista hacia adelante
    recorrerAdelante(inicio);
    printf("\n");

    // 3. Luego inserta otros valores al final
    printf("\n Fase de Inserción al Final \n");
    printf("¿Cuántos valores desea insertar al final? ");
    if (scanf("%d", &num_valores) != 1 || num_valores < 0) {
         printf("Entrada inválida. Terminando el programa.\n");
         liberar(inicio);
         return 1;
    }

    for (int i = 0; i < num_valores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
             printf("Entrada inválida. Terminando el programa.\n");
             liberar(inicio);
             return 1;
        }
        insertarFinal(&inicio, valor);
    }
    
    // 3. Muestra la lista nuevamente.
    recorrerAdelante(inicio);
    printf("\n");

    // Paso A3. Recorrido en ambos sentidos
    printf("\n Fase de Recorrido \n");
    // 1. Implementa y 2. Verifica Recorrido Adelante
    recorrerAdelante(inicio); 
    // 1. Implementa y 2. Verifica Recorrido Atrás
    recorrerAtras(inicio);
    printf("\n");

    // Paso A4. Eliminación
    printf("\n Fase de Eliminación\n");
    // 1. Pregunta al usuario el valor a eliminar.
    printf("Ingrese el valor a eliminar: ");
    if (scanf("%d", &valor) != 1) {
         printf("Entrada inválida. Terminando el programa.\n");
         liberar(inicio);
         return 1;
    }
    
    eliminar(&inicio, valor);
    
    printf("\nLista después de la eliminación:\n");
    recorrerAdelante(inicio);
    recorrerAtras(inicio);
    printf("\n");

    // Paso A5. Liberación
    // Libera toda la memoria de la lista con free()
    liberar(inicio); 

    return 0;
}



//Segundo codigo 
#include <stdio.h>
#include <stdlib.h>

// Paso B1. Creación y características: Estructura circular
struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// FUNCIONES CIRCULARES
// Paso B2. Inserción circular al final
void insertarFinalCircular(struct Nodo **inicio, int valor) {
    // 1. Crear nuevo nodo
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: No se pudo reservar memoria.\n");
        return;
    }
    nuevo->dato = valor;

    // Caso 1: La lista está vacía (el nuevo nodo se apunta a sí mismo)
    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        printf("-> Insertado %d al final (lista vacía).\n", valor);
        return;
    }

    // Caso 2: Lista no vacía (se inserta al final)
    // El puntero anterior del inicio es el último nodo.
    struct Nodo *ultimo = (*inicio)->anterior;

    // Conexiones del nuevo nodo
    nuevo->siguiente = *inicio; // nuevo apunta hacia adelante al primero
    nuevo->anterior = ultimo;   // nuevo apunta hacia atrás al último

    // Actualizar enlaces circulares del primero y último
    ultimo->siguiente = nuevo; // El antiguo último apunta hacia adelante al nuevo
    (*inicio)->anterior = nuevo; // El primero apunta hacia atrás al nuevo último

    printf("-> Insertado %d al final.\n", valor);
}

// Paso B3. Recorrido circular
void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    
    printf("\nRecorrido Circular: ");
    struct Nodo *actual = inicio;
    
    // Recorre desde el inicio hasta que vuelve a ser el inicio
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);
    
    printf("\n");
    
    // Verificación de enlaces: Mostrar el último que apunta al inicio y viceversa
    printf("Verificación de enlaces (Último <-> Primero):\n");
    struct Nodo *ultimo = inicio->anterior;
    printf("Último (%d).siguiente apunta a: %d\n", ultimo->dato, ultimo->siguiente->dato);
    printf("Primero (%d).anterior apunta a: %d\n", inicio->dato, inicio->anterior->dato);
}

// Paso B4. Eliminación circular
void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) {
        printf("La lista está vacía, no se puede eliminar %d.\n", valor);
        return;
    }
    
    struct Nodo *actual = *inicio;
    struct Nodo *nodo_a_eliminar = NULL;

    // Buscar el nodo a eliminar (recorrido circular)
    do {
        if (actual->dato == valor) {
            nodo_a_eliminar = actual;
            break;
        }
        actual = actual->siguiente;
    } while (actual != *inicio);

    // Si no se encuentra el valor
    if (nodo_a_eliminar == NULL) {
        printf("El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    // Caso 1: Único nodo en la lista
    if (nodo_a_eliminar->siguiente == nodo_a_eliminar) {
        printf("-> Eliminado %d (Único nodo). La lista queda vacía.\n", valor);
        free(nodo_a_eliminar);
        *inicio = NULL;
        return;
    }

    // Ajustar los punteros del nodo anterior y siguiente
    nodo_a_eliminar->anterior->siguiente = nodo_a_eliminar->siguiente;
    nodo_a_eliminar->siguiente->anterior = nodo_a_eliminar->anterior;

    // Caso 2: El nodo a eliminar es el primero (*inicio)
    if (nodo_a_eliminar == *inicio) {
        *inicio = nodo_a_eliminar->siguiente; // El inicio se mueve al siguiente
    }

    // 3. Libera la memoria del nodo eliminado.
    printf("-> Eliminado el valor %d.\n", valor);
    free(nodo_a_eliminar);
}

// Función para liberar la memoria de la lista (copiada de la Parte A, pero adaptada para circularidad)
void liberarCircular(struct Nodo **inicio) {
    if (*inicio == NULL) {
        printf("Memoria ya estaba liberada (lista vacía).\n");
        return;
    }
    
    struct Nodo *actual = *inicio;
    struct Nodo *siguiente;

    // 1. Romper el ciclo circular
    (*inicio)->anterior->siguiente = NULL; 
    
    // 2. Liberar de forma secuencial
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    *inicio = NULL;
    printf("Memoria liberada correctamente.\n");
}

// FUNCIÓN PRINCIPAL (PRUEBA)
int main() {
    struct Nodo *inicio = NULL;
    int num_valores, valor;

    // Paso B2. Inserción circular al final 
    printf(" Fase de Creación e Inserción Circular\n");
    printf("¿Cuántos valores desea insertar al final de la lista circular? ");
    if (scanf("%d", &num_valores) != 1 || num_valores < 0) {
        printf("Entrada inválida. Terminando el programa.\n");
        liberarCircular(&inicio);
        return 1;
    }

    for (int i = 0; i < num_valores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        if (scanf("%d", &valor) != 1) {
            printf("Entrada inválida. Terminando el programa.\n");
            liberarCircular(&inicio);
            return 1;
        }
        insertarFinalCircular(&inicio, valor);
    }
    
    // Paso B3. Recorrido circular
    printf("\n Fase de Recorrido Circular\n");
    recorrerCircular(inicio);
    printf("\n");
    
    // Paso B4. Eliminación circular
    printf("\n Fase de Eliminación Circular\n");
    if (inicio != NULL) {
        printf("Ingrese el valor a eliminar (intente el primero, el último o uno de en medio): ");
        if (scanf("%d", &valor) != 1) {
            printf("Entrada inválida. Terminando el programa.\n");
            liberarCircular(&inicio);
            return 1;
        }
        
        eliminarCircular(&inicio, valor);

        printf("\nLista resultante después de la eliminación:\n");
        if (inicio != NULL) {
            recorrerCircular(inicio);
        } else {
            printf("La lista está vacía.\n");
        }
    } else {
        printf("No hay nodos para eliminar.\n");
    }
    
    printf("\n");

    // Liberación final
    liberarCircular(&inicio); 

    return 0;
}