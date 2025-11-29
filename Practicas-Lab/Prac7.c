//Primer codigo 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Paso A1.1: Creación de la estructura
// Estructura de cada nodo de la lista
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Puntero global (o local a main) para la cabeza, inicializado en NULL
// struct Nodo *cabeza = NULL; // Lo manejaremos como puntero doble para las funciones

// Paso A1.2: Implementación de funciones básicas
// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo_nodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL;
    return nuevo_nodo;
}

// insertarInicio(struct Nodo **cabeza, int valor)
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    
    // 1. El nuevo nodo apunta a la antigua cabeza
    nuevo->siguiente = *cabeza;
    
    // 2. La cabeza apunta al nuevo nodo
    *cabeza = nuevo;
    printf("Insertado al inicio: %d. ", valor);
}

// recorrer(struct Nodo *cabeza)
void recorrer(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Contenido de la Lista: ");
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// eliminar(struct Nodo **cabeza, int valor)
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    // Caso 1: El nodo a eliminar es la cabeza
    if (actual != NULL && actual->dato == valor) {
        *cabeza = actual->siguiente; // Mover la cabeza al siguiente
        printf("Eliminado: %d (Cabeza).\n", valor);
        free(actual); // Liberar el nodo
        return;
    }

    // Buscar el nodo, manteniendo un rastro del anterior
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si 'actual' es NULL, el valor no se encontró
    if (actual == NULL) {
        printf("ERROR: El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    // Caso 2: El nodo a eliminar está en medio o al final
    // El nodo anterior apunta al siguiente del nodo actual (saltando 'actual')
    anterior->siguiente = actual->siguiente;
    
    printf("Eliminado: %d.\n", valor);
    free(actual); // Liberar el nodo
}

// liberar(struct Nodo *cabeza)
void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual); // Liberar la memoria del nodo actual
        actual = siguiente;
    }
}

// Función principal para ejecutar los pasos 2,3 y 4
int main() {
    struct Nodo *cabeza = NULL; // 1. Puntero *cabeza inicializado en NULL
    int num_valores;
    int valor_a_insertar;
    int valor_a_eliminar;

    printf("Lista Enlazada Simple\n");

    // Paso A2. Inserción
    printf("\nPaso A2: Inserción al Inicio\n");
    
    // 1. Pide al usuario cuántos valores desea insertar
    printf("¿Cuántos valores desea insertar al inicio de la lista? ");
    if (scanf("%d", &num_valores) != 1 || num_valores < 1) {
        printf("Entrada inválida. Usaremos 3 valores por defecto.\n");
        num_valores = 3;
    }

    for (int i = 0; i < num_valores; i++) {
        // Pide el valor y lo inserta
        printf("Ingrese el valor %d: ", i + 1);
        if (scanf("%d", &valor_a_insertar) != 1) {
             printf("Entrada inválida. Terminando inserción.\n");
             break;
        }
        
        // 2. Inserta cada nuevo nodo al inicio de la lista
        insertarInicio(&cabeza, valor_a_insertar);
        
        // 3. Muestra el contenido después de cada inserción
        recorrer(cabeza);
    }
    
    // Paso A3. Recorrido y eliminación
    printf("\nPaso A3: Recorrido y Eliminación\n");
    
    // 1. Recorre la lista e imprime todos los nodos
    printf("Estado final de la lista antes de eliminar:\n");
    recorrer(cabeza);

    // 2. Pregunta al usuario qué valor desea eliminar
    printf("\n¿Qué valor desea eliminar de la lista? ");
    if (scanf("%d", &valor_a_eliminar) != 1) {
        printf("Entrada inválida. No se realizará la eliminación.\n");
    } else {
        // 3. Implementa la lógica de eliminación
        eliminar(&cabeza, valor_a_eliminar);
        
        // 4. Muestra la lista actualizada después de eliminar
        printf("\nLista después de la eliminación:\n");
        recorrer(cabeza);
    }

    // Paso A4. Liberación de memoria
    printf("\nPaso A4: Liberación de Memoria\n");
    liberar(cabeza);
    
    // 2. Muestra un mensaje final
    printf("Memoria liberada correctamente.\n");
    
    return 0;
}



//Segundo codigo 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura Base del Nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Funciones Auxiliares
// Función para crear un nuevo nodo
struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo_nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo_nodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = NULL; // Temporalmente NULL
    return nuevo_nodo;
}

// Paso B2. Inserción Circular (Al Inicio)
// insertaInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor)
void insertaInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    
    if (*cabeza == NULL) {
        // Caso 1: Lista vacía. El nuevo nodo apunta a sí mismo.
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        // Caso 2: Lista no vacía.
        
        // 1. El nuevo nodo apunta a la antigua cabeza.
        nuevo->siguiente = *cabeza;
        
        // 2. El último nodo apunta al nuevo nodo (cerrando el círculo).
        (*ultimo)->siguiente = nuevo;
        
        // 3. La nueva cabeza es el nodo recién insertado.
        *cabeza = nuevo;
    }
    printf("[Circular] Insertado al inicio: %d. ", valor);
}

// Paso B3. Recorrido Circular
// recorrerCircular(struct Nodo *cabeza)
void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("[Circular] La lista está vacía.\n");
        return;
    }
    printf("[Circular] Contenido de la Lista: ");
    struct Nodo* actual = cabeza;
    
    // Recorremos usando un bucle do-while para garantizar que se ejecute al menos una vez
    // y se detenga cuando 'actual' vuelva al nodo 'cabeza'.
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    
    printf("Inicio (%d)\n", cabeza->dato); // Muestra el enlace circular
}

// Paso B4. Eliminación Circular
void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("[Circular] ERROR: La lista está vacía, no se puede eliminar %d.\n", valor);
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    // Búsqueda del nodo (se detiene cuando encuentra el valor o da la vuelta completa)
    do {
        if (actual->dato == valor) {
            break; // Nodo encontrado
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);
    
    // Si actual vuelve a la cabeza y no encontró el valor (significa que el valor no existe)
    if (actual->dato != valor) {
        printf("[Circular] ERROR: El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    // Lógica de Eliminación
    // Caso 1: El nodo a eliminar es el único en la lista
    if (actual == *cabeza && actual == *ultimo) {
        free(actual);
        *cabeza = NULL;
        *ultimo = NULL;
        printf("[Circular] Eliminado: %d. Lista vaciada.\n", valor);
        return;
    }
    
    // Caso 2: El nodo a eliminar es la cabeza (pero no es el único)
    if (actual == *cabeza) {
        *cabeza = actual->siguiente;      // La nueva cabeza es el segundo nodo
        (*ultimo)->siguiente = *cabeza;    // El último nodo apunta a la nueva cabeza
    } 
    // Caso 3: El nodo a eliminar es el último
    else if (actual == *ultimo) {
        anterior->siguiente = *cabeza; // El penúltimo nodo apunta a la cabeza
        *ultimo = anterior;            // El penúltimo ahora es el nuevo último
    } 
    // Caso 4: El nodo a eliminar es intermedio
    else {
        anterior->siguiente = actual->siguiente; // Enlaza el anterior con el siguiente
    }
    
    printf("[Circular] Eliminado: %d.\n", valor);
    free(actual); // Liberar la memoria del nodo eliminado
}

// liberarCircular(struct Nodo *cabeza)
    void liberarCircular(struct Nodo **cabeza, struct Nodo **ultimo) {
    if (*cabeza == NULL) return;
    
    struct Nodo *actual = *cabeza;
    struct Nodo *siguiente;
    
    // Deshacer el enlace circular primero
    (*ultimo)->siguiente = NULL;
    
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
    *ultimo = NULL;
}

// Función principal (main)
int main() {
    // Paso B1.2: Declarar punteros
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int num_valores;
    int valor_a_insertar;
    int valor_a_eliminar;

    printf("Lista Enlazada Circular\n");

    // Paso B2. Inserción Circular
    printf("\nPaso B2: Inserción al Inicio\n");
    
    // 1. Pide al usuario cuántos valores desea insertar
    printf("¿Cuántos valores desea insertar al inicio de la lista circular? ");
    if (scanf("%d", &num_valores) != 1 || num_valores < 1) {
        printf("Entrada inválida. Usaremos 4 valores por defecto (10, 20, 30, 40).\n");
        num_valores = 4;
    }
    
    int valores_defecto[] = {10, 20, 30, 40};
    for (int i = 0; i < num_valores; i++) {
        if (i < 4) {
            valor_a_insertar = valores_defecto[i];
            printf("Insertando valor por defecto: %d\n", valor_a_insertar);
        } else {
            printf("Ingrese el valor %d: ", i + 1);
            if (scanf("%d", &valor_a_insertar) != 1) {
                 printf("Entrada inválida. Terminando inserción.\n");
                 break;
            }
        }
        
        // 2. Inserta cada nuevo nodo al inicio de la lista
        insertaInicioCircular(&cabeza, &ultimo, valor_a_insertar);
        
        // 3. Muestra el contenido después de cada inserción
        recorrerCircular(cabeza);
    }
    
    //Paso B3. Recorrido Circular
    printf("\nPaso B3: Recorrido Circular Final\n");
    recorrerCircular(cabeza);

    //Paso B4. Eliminación
    printf("\nPaso B4: Eliminación Circular\n");
    
    // 1. Eliminar valor intermedio (ej: 20)
    valor_a_eliminar = 20; 
    printf("Intentando eliminar valor intermedio (%d)...\n", valor_a_eliminar);
    eliminarCircular(&cabeza, &ultimo, valor_a_eliminar);
    recorrerCircular(cabeza);
    
    // 2. Eliminar la cabeza (ej: 40)
    valor_a_eliminar = 40; 
    printf("\nIntentando eliminar la cabeza (%d)...\n", valor_a_eliminar);
    eliminarCircular(&cabeza, &ultimo, valor_a_eliminar);
    recorrerCircular(cabeza); // Nueva cabeza es 30.
    
    // 3. Eliminar el último (ej: 10)
    valor_a_eliminar = 10;
    printf("\nIntentando eliminar el último (%d)...\n", valor_a_eliminar);
    eliminarCircular(&cabeza, &ultimo, valor_a_eliminar);
    recorrerCircular(cabeza); // Nuevo último es 30.
    
    // 4. Eliminar el valor que queda (30)
    valor_a_eliminar = 30;
    printf("\nIntentando eliminar el único valor restante (%d)...\n", valor_a_eliminar);
    eliminarCircular(&cabeza, &ultimo, valor_a_eliminar);
    recorrerCircular(cabeza); // Lista vacía
    
    // Paso Final. Liberación de memoria 
    printf("\nLiberación de Memoria\n");
    liberarCircular(&cabeza, &ultimo);
    printf("Memoria liberada correctamente.\n");

    return 0;
}
