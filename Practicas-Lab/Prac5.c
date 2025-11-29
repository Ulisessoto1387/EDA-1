//Primer codigo y segundo codigo  
#include <stdio.h>
#include <limits.h> // Para usar INT_MIN como valor de error

// Constante para el tamaño máximo de ambas estructuras
#define MAX_SIZE 5

// Estructura para la Pila
typedef struct {
    int arreglo[MAX_SIZE];
    int tope; // Indica la posición del último elemento insertado
} Pila;

// Estructura para la Cola
typedef struct {
    int arreglo[MAX_SIZE];
    int frente; // Índice del primer elemento (el que va a salir)
    int final;  // Índice del último elemento (el que acaba de entrar)
} Cola;

// FUNCIONES DE UTILIDAD
// Función para mostrar el estado de una Pila
void mostrar_pila(Pila *p) {
    printf("Estado actual de la Pila (TOPE -> Fondo): [");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d", p->arreglo[i]);
        if (i < p->tope) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Función para mostrar el estado de una Cola
void mostrar_cola(Cola *c) {
    printf("Estado actual de la Cola (FRENTE -> Final): [");
    // La cola solo existe si final >= frente
    if (c->final >= c->frente) {
        for (int i = c->frente; i <= c->final; i++) {
            printf("%d", c->arreglo[i]);
            if (i < c->final) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

// IMPLEMENTACIÓN DE PILA (LIFO)
// Paso 1: Inicializar la Pila
void inicializar_pila(Pila *p) {
    p->tope = -1; // -1 indica que la pila está vacía
    printf("Pila");
    printf("\nPila inicializada vacía.\n");
}

// Paso 2: Insertar elementos (PUSH)
void push(Pila *p, int dato) {
    if (p->tope < MAX_SIZE - 1) {
        p->tope++; // Mueve el tope a la siguiente posición
        p->arreglo[p->tope] = dato; // Inserta el dato
        printf("PUSH: Se apiló el elemento %d.\n", dato);
        mostrar_pila(p);
    } else {
        printf("ERROR: Pila llena. No se puede apilar %d.\n", dato);
    }
}

// Paso 3: Extraer elementos (POP)
int pop(Pila *p) {
    if (p->tope >= 0) {
        int dato_salida = p->arreglo[p->tope]; // Guarda el elemento superior
        p->tope--; // Decrementa el tope (el elemento ya no es accesible)
        printf("POP: Se extrajo el elemento %d.\n", dato_salida);
        return dato_salida;
    } else {
        printf("ERROR: Pila vacía. No se puede desapilar.\n");
        return INT_MIN; // Retorna un valor de error
    }
}

// IMPLEMENTACIÓN DE COLA (FIFO)
// Paso 1: Inicializar la Cola
void inicializar_cola(Cola *c) {
    c->frente = 0;
    c->final = -1; // -1 indica que la cola está vacía
    printf("\n Cola ");
    printf("\nCola inicializada vacía.\n");
}

// Paso 2: Insertar elementos (ENQUEUE)
void enqueue(Cola *c, int dato) {
    // Si la cola está llena (hemos usado todo el espacio del arreglo)
    if (c->final == MAX_SIZE - 1) {
        printf("ERROR: Cola llena. No se puede encolar %d.\n", dato);
        return;
    }
    
    // Mueve el final a la siguiente posición e inserta
    c->final++;
    c->arreglo[c->final] = dato;
    printf("ENQUEUE: Se encoló el elemento %d.\n", dato);
    mostrar_cola(c);
}

// Paso 3: Extraer elementos (DEQUEUE)
int dequeue(Cola *c) {
    // Si la cola está vacía (final < frente)
    if (c->final < c->frente) {
        printf("ERROR: Cola vacía. No se puede desencolar.\n");
        return INT_MIN; // Retorna un valor de error
    }
    
    // Guarda el elemento del frente
    int dato_salida = c->arreglo[c->frente];
    // Avanza el frente
    c->frente++;
    printf("DEQUEUE: Se extrajo el elemento %d.\n", dato_salida);

    // Opcional: Si el frente supera al final, reiniciamos la cola para 'limpiar'
    if (c->frente > c->final) {
        c->frente = 0;
        c->final = -1;
        printf("(Cola vacía y reiniciada.)\n");
    } else {
        mostrar_cola(c);
    }
    
    return dato_salida;
}

// FUNCIÓN PRINCIPAL (MAIN)
int main() {
    Pila mi_pila;
    Cola mi_cola;
    int num_op, dato;
    int pila_registro[MAX_SIZE];
    int cola_registro[MAX_SIZE];
    int registro_count = 0;
    
    // OPERACIONES DE PILA
    inicializar_pila(&mi_pila);
    // Insertar elementos (PUSH)
    printf("\n Paso 2: Operación PUSH \n");
    printf("¿Cuántos elementos quiere apilar? (Máximo %d): ", MAX_SIZE);
    scanf("%d", &num_op);
    if (num_op > MAX_SIZE) num_op = MAX_SIZE;
    
    printf("Ingrese los %d elementos:\n", num_op);
    for (int i = 0; i < num_op; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &dato);
        push(&mi_pila, dato);
    }
    
    // Guardamos los datos insertados en el orden LIFO para la comparación
    // Los datos insertados en Pila y Cola deben ser los mismos para la comparación
    for (int i = 0; i < mi_pila.tope + 1; i++) {
        pila_registro[registro_count] = mi_pila.arreglo[i];
        registro_count++;
    }

    // Extraer elementos (POP)
    printf("\n Paso 3: Operación POP \n");
    printf("¿Cuántos elementos quiere desapilar? (Máximo %d): ", registro_count);
    scanf("%d", &num_op);
    if (num_op > registro_count) num_op = registro_count;
    
    for (int i = 0; i < num_op; i++) {
        pop(&mi_pila);
    }
    
    // OPERACIONES DE COLA 
    inicializar_cola(&mi_cola);
    // Insertar elementos en la cola (ENQUEUE)
    printf("\n Paso 5: Operación ENQUEUE \n");
    printf("Encolando los mismos %d elementos de la pila:\n", registro_count);
    mi_cola.frente = 0; // Asegura que empiece desde el inicio
    mi_cola.final = -1; // Asegura que empiece vacía
    
    for (int i = 0; i < registro_count; i++) {
        enqueue(&mi_cola, pila_registro[i]);
    }

    // Guardamos el orden de inserción de la cola (es el mismo que el de la pila)
    for (int i = 0; i < registro_count; i++) {
        cola_registro[i] = mi_cola.arreglo[i];
    }
    
    // Extraer elementos de la cola (DEQUEUE)
    printf("\n Paso 6: Operación DEQUEUE \n");
    printf("¿Cuántos elementos quiere desencolar? (Máximo %d): ", registro_count);
    scanf("%d", &num_op);
    if (num_op > registro_count) num_op = registro_count;
    
    for (int i = 0; i < num_op; i++) {
        dequeue(&mi_cola);
    }

    // Paso 7: Comparación
    printf("\n Paso 7: COMPARACIÓN DE ORDEN DE SALIDA\n");
    // Los elementos insertados fueron:
    printf("\nElementos insertados (orden de entrada): [");
    for (int i = 0; i < registro_count; i++) {
        printf("%d", pila_registro[i]);
        if (i < registro_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Orden de salida de la Pila (Inverso)
    printf("\nOrden de SALIDA de la Pila (LIFO): [");
    for (int i = registro_count - 1; i >= 0; i--) {
        printf("%d", pila_registro[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("  -> La Pila funciona: El último elemento insertado es el primero en salir.\n");

    // Orden de salida de la Cola (Mismo orden)
    printf("\nOrden de SALIDA de la Cola (FIFO): [");
    for (int i = 0; i < registro_count; i++) {
        printf("%d", cola_registro[i]);
        if (i < registro_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("  -> La Cola funciona: El primer elemento insertado es el primero en salir.\n");

    return 0;
}



