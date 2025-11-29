#include <stdio.h> 
int main(void) {
    int a[5] = {2, 4, 6, 8, 10}; // Declara un arreglo 'a' de 5 enteros.
    int *p = a; // Declara un puntero 'p' y lo inicializa para que apunte al inicio del arreglo 'a' (es decir, a 'a[0]', el valor 2).

    printf("1) a[1] = %d\n", a[1]); // Imprime el valor en el índice 1 del arreglo (4).
    printf("2) *(a+3) = %d\n", *(a+3));  // Imprime el valor en la dirección 'a + 3', que es el elemento en el índice 3 (8).
    printf("3) *p++ = %d\n", *p++);     // Post-incremento: Imprime el valor actual de p (2).
    printf("4) *++p = %d\n", *++p);     // Pre-incremento: Primero, p avanza 1 posición (de 4 a 6). Luego, imprime el valor 6.
    printf("5) p[1] = %d\n", p[1]);  // Es equivalente a *(p + 1). Imprime el valor 1 posición delante de p, que es 8.
    printf("6) *(p+=2) = %d\n", *(p+=2)); // Suma y Asignación: p avanza 2 posiciones (de 6 a 10). Imprime el valor p apunta a 10.
    printf("7) p - a = %ld\n", p - a); //Resta de punteros: Se calcula la diferencia entre la posición final de p (a[4]) y el inicio del arreglo (a[0]). Esto es 4 elementos.

    return 0; 
}

