//Primer codigo 
#include <stdio.h>
#include <stdbool.h>

// Paso A1. Inicialización 
#define MAX 5 // Definimos un tamaño máximo para la cola

// 1. Define una estructura ColaCircular
typedef struct {
    int datos[MAX];
    int frente; // Índice del primer elemento
    int final;  // Índice de la última posición ocupada + 1 (donde se insertará el siguiente)
    int tamanio; // Contador de elementos actual
} ColaCircular;

// 2. Inicializa la cola vacía
void inicializarCola(ColaCircular *q) {
    q->frente = 0;
    q->final = 0;
    q->tamanio = 0;
    // 3. Muestra un mensaje: 'Cola circular inicializada'.
    printf("Cola circular inicializada (MAX: %d).\n", MAX);
}

// Paso A2. Operaciones

// Verifica si la cola está vacía
bool isEmpty(ColaCircular *q) {
    // Condición de vacío: size == 0
    return q->tamanio == 0;
}

// Verifica si la cola está llena
bool isFull(ColaCircular *q) {
    // Condición de lleno: size == MAX
    return q->tamanio == MAX;
}

// Agrega un elemento a la cola (Enqueue)
void enqueue(ColaCircular *q, int valor) {
    if (isFull(q)) {
        printf("ERROR: Cola llena, no se puede encolar %d.\n", valor);
        return;
    }
    
    q->datos[q->final] = valor;
    // Avanzar índice final: (índice + 1) % MAX
    q->final = (q->final + 1) % MAX;
    q->tamanio++;
    printf("Encolado: %d.\n", valor);
}

// Elimina y devuelve el elemento del frente (Dequeue)
int dequeue(ColaCircular *q) {
    if (isEmpty(q)) {
        printf("EROR: Cola vacía, no se puede desencolar.\n");
        return -1; // Valor de error
    }
    
    int valor = q->datos[q->frente];
    // Avanzar índice frente: (índice + 1) % MAX
    q->frente = (q->frente + 1) % MAX;
    q->tamanio--;
    printf("Desencolado: %d.\n", valor);
    return valor;
}

// Devuelve el elemento del frente sin eliminarlo (Peek)
int peek(ColaCircular *q) {
    if (isEmpty(q)) {
        printf("ERROR: Cola vacía, no hay elemento para ver.\n");
        return -1; // Valor de error
    }
    
    return q->datos[q->frente];
}

// Imprime el estado actual de la cola
void printQueue(ColaCircular *q) {
    printf("\nEstado Actual de la Cola\n");
    printf(" Tamaño actual: %d / %d\n", q->tamanio, MAX);
    printf(" Índice Frente: %d\n", q->frente);
    printf(" Índice Final: %d\n", q->final);
    
    if (isEmpty(q)) {
        printf("  [Cola vacía]\n");
        return;
    }
    
    printf("Elementos (frente -> final): ");
    int i = q->frente;
    int count = 0;
    
    // Recorremos la cola desde el frente hasta que hayamos contado 'tamaño' elementos
    while (count < q->tamanio) {
        printf("%d", q->datos[i]);
        if (count < q->tamanio - 1) {
            printf(" -> ");
        }
        i = (i + 1) % MAX; // Avanzamos circularmente
        count++;
    }
    
    printf("\n");
}

// Función principal para las pruebas
int main() {
    ColaCircular miCola;
    inicializarCola(&miCola);
    
    // Paso A3. Pruebas
    printf("\nINICIO DE PRUEBAS\n");

    // 1. Encolar: 5, 10, 15
    printf("\nPrueba 1: Encolar 5, 10, 15 \n");
    enqueue(&miCola, 5);
    enqueue(&miCola, 10);
    enqueue(&miCola, 15);
    printQueue(&miCola);

    // 2. Desencolar uno
    printf("\nPrueba 2: Desencolar uno \n");
    int desencolado = dequeue(&miCola);
    printf("Elemento en el frente (peek): %d\n", peek(&miCola));
    printQueue(&miCola);

    // 3. Encolar: 20, 25, 30
    printf("\nPrueba 3: Encolar 20, 25, 30 \n");
    // Observa aquí cómo el 20 y el 25 ocupan los espacios liberados (se reciclan)
    enqueue(&miCola, 20); // Ocupará el índice 0
    enqueue(&miCola, 25); // Ocupará el índice 1
    
    // Intentaremos encolar uno más para llenar la cola
    enqueue(&miCola, 30); // Ocupará el índice 4, y la cola estará llena
    
    // Intentaremos encolar un elemento extra para probar isFull
    enqueue(&miCola, 35);
    
    printQueue(&miCola);
    
    // Prueba extra de vaciado
    printf("\nPrueba 4: Vaciado y Peek \n");
    dequeue(&miCola);
    dequeue(&miCola);
    dequeue(&miCola);
    dequeue(&miCola);
    printQueue(&miCola);
    
    peek(&miCola); // Probar peek en cola vacía
    dequeue(&miCola); // Probar dequeue en cola vacía

    printf("\n FIN DE PRUEBAS \n");
    
    return 0;
}



//Segundo codigo 
#include <stdio.h>
#include <stdbool.h>

// Paso B1. Inicialización
#define MAX 5 // Definimos un tamaño máximo

// 1. Define estructura Deque
typedef struct {
    int datos[MAX];
    int frente; // Índice del primer elemento
    int tamanio; // Contador de elementos actual
} Deque;

// 2. Inicializa con frente = 0, size = 0.
void inicializarDeque(Deque *d) {
    d->frente = 0;
    d->tamanio = 0;
    printf("Cola Doble (Deque) inicializada (MAX: %d).\n", MAX);
}

// Funciones Auxiliares
bool isEmpty(Deque *d) {
    return d->tamanio == 0;
}

bool isFull(Deque *d) {
    return d->tamanio == MAX;
}

// Paso B2. Operaciones

// I. Inserción por el Frente
void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf("ERROR: Deque lleno, no se puede insertar %d por el frente.\n", valor);
        return;
    }
    
    // El nuevo frente se calcula moviendo el índice 'frente' una posición hacia atrás,
    // usando la operación circular: (índice - 1 + MAX) % MAX
    d->frente = (d->frente - 1 + MAX) % MAX;
    
    d->datos[d->frente] = valor;
    d->tamanio++;
    printf("Insertado por Frente: %d.\n", valor);
}

// II. Inserción por el Final
void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf("ERROR: Deque lleno, no se puede insertar %d por el final.\n", valor);
        return;
    }
    
    // El índice 'final' (donde insertar) es (frente + tamanio) % MAX
    int rear_index = (d->frente + d->tamanio) % MAX;
    
    d->datos[rear_index] = valor;
    d->tamanio++;
    printf("Insertado por Final: %d.\n", valor);
}

// III. Eliminación por el Frente
int delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf("ERROR: Deque vacío, no se puede eliminar por el frente.\n");
        return -1;
    }
    
    int valor = d->datos[d->frente];
    // No es estrictamente necesario, pero ayuda a visualizar: d->datos[d->frente] = 0; 
    
    // Mover 'frente' una posición hacia adelante
    d->frente = (d->frente + 1) % MAX;
    d->tamanio--;
    printf("Eliminado por Frente: %d.\n", valor);
    return valor;
}

// IV. Eliminación por el Final
int delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("ERROR: Deque vacío, no se puede eliminar por el final.\n");
        return -1;
    }
    
    // El índice del ÚLTIMO elemento es: (frente + tamanio - 1) % MAX
    int rear_index = (d->frente + d->tamanio - 1) % MAX;
    int valor = d->datos[rear_index];
    // No es estrictamente necesario, pero ayuda a visualizar: d->datos[rear_index] = 0; 
    
    // Simplemente decrementamos el tamaño, lo que implícitamente "elimina" el elemento
    // y la fórmula de 'rear' apuntará a la nueva posición final.
    d->tamanio--;
    printf("Eliminado por Final: %d.\n", valor);
    return valor;
}

// V. Observar el Frente
int peek_front(Deque *d) {
    if (isEmpty(d)) {
        return -1;
    }
    return d->datos[d->frente];
}

// VI. Observar el Final
int peek_rear(Deque *d) {
    if (isEmpty(d)) {
        return -1;
    }
    // El índice del ÚLTIMO elemento es: (frente + tamanio - 1) % MAX
    int rear_index = (d->frente + d->tamanio - 1) % MAX;
    return d->datos[rear_index];
}

// Imprime el estado actual del Deque
void printDeque(Deque *d) {
    printf("\nEstado Actual del Deque\n");
    printf("Tamaño actual: %d / %d\n", d->tamanio, MAX);
    
    if (isEmpty(d)) {
        printf("  [Deque vacío]\n");
        printf("  Frente: %d | Final (calculado): -\n", d->frente);
        return;
    }

    // Calcular el índice del último elemento ocupado
    int rear_element_index = (d->frente + d->tamanio - 1) % MAX;
    
    printf("Frente (índice 1er elemento): %d (%d)\n", d->frente, d->datos[d->frente]);
    printf("Final (índice último elemento): %d (%d)\n", rear_element_index, d->datos[rear_element_index]);
    
    printf("Elementos (frente -> final): ");
    
    int i = d->frente;
    int count = 0;
    
    while (count < d->tamanio) {
        printf("%d", d->datos[i]);
        if (count < d->tamanio - 1) {
            printf(" -> ");
        }
        i = (i + 1) % MAX;
        count++;
    }
    
    printf ("\n"); 
}


// Función principal para las pruebas
int main() {
    Deque miDeque;
    inicializarDeque(&miDeque);
    
    // Paso B3. Pruebas 
    printf("\nINICIO DE PRUEBAS\n");

    // 1. insert_front(10)
    printf("\nPrueba 1: Inserción Inicial\n");
    insert_front(&miDeque, 10); // Frente es 4 (porque (0 - 1 + 5) % 5 = 4)
    printDeque(&miDeque);

    // 2. insert_rear(15), insert_rear(20)
    printf("\nPrueba 2: Inserciones por Final\n");
    insert_rear(&miDeque, 15); // Final es 0
    insert_rear(&miDeque, 20); // Final es 1
    
    printf("Peek Frente: %d | Peek Final: %d\n", peek_front(&miDeque), peek_rear(&miDeque));
    printDeque(&miDeque);

    // 3. insert_front(30)
    printf("\nPrueba 3: Inserción por Frente (Movimiento circular)\n");
    insert_front(&miDeque, 30); // Frente se mueve de 4 a 3
    
    // 4. insert_rear(40)
    insert_rear(&miDeque, 40); // Final se mueve de 1 a 2
    
    // 4. imprime estado (índices primero y último).
    printDeque(&miDeque);

    // 5. delete_front() y delete_rear()
    printf("\nPrueba 4: Eliminaciones por ambos lados\n");
    delete_front(&miDeque); // Elimina el 30. El nuevo frente es 4 (el 10)
    delete_rear(&miDeque);  // Elimina el 40. El nuevo final es 1 (el 20)
    printDeque(&miDeque);
    
    // 6. Inserta nuevos valores y comprueba cómo se mueven los índices.
    printf("\nPrueba 5: Nuevas Inserciones para comprobar el reciclaje\n");
    insert_front(&miDeque, 5); // Frente se mueve de 4 a 3. Ocupa el espacio del 30
    insert_rear(&miDeque, 50);  // Final se mueve de 1 a 2. Ocupa el espacio del 40
    
    printDeque(&miDeque);
    
    printf("\n*Reciclaje observado*: Frente ahora es 3 (5), Final es 2 (50).\n");
    printf("El índice 3 y 2 han sido reutilizados.\n");
    
    printf("\n FIN DE PRUEBAS\n");
    
    return 0;
}