#include <stdio.h>
#include <string.h>

#define MAX_PELICULAS 100
#define MAX_GENERO 20
#define MAX_TITULO 50
#define MAX_DIRECTOR 50

// 1. Definir una estructura pelicula
typedef struct {
    char titulo[MAX_TITULO];
    char director[MAX_DIRECTOR];
    int anio;
    char genero[MAX_GENERO];
} pelicula;

// Declaración de funciones
void capturarDatos(pelicula videoteca[], int *numPeliculas);
void imprimirInverso(pelicula videoteca[], int numPeliculas);
void buscarPelicula(pelicula videoteca[], int numPeliculas);
void contarPorGenero(pelicula videoteca[], int numPeliculas);
int validarDatos(int numDirectores, int numPeliculas);

// 2. Declara videoteca
pelicula videoteca[MAX_PELICULAS];
int numPeliculas = 0;

int main() {
    int opcion;
    int numDirectores;

    printf("Bienvenido a la gestion de videoteca.\n");

    // Captura inicial de datos
    capturarDatos(videoteca, &numPeliculas);

    // Validación simple
    printf("Ingrese el numero de directores para la validacion: ");
    scanf("%d", &numDirectores);
    if (!validarDatos(numDirectores, numPeliculas)) {
        printf("Error de validacion. Saliendo del programa.\n");
        return 1;
    }

    do {
        printf("\n--- MENU DE OPCIONES ---\n");
        printf("1. Imprimir peliculas en orden inverso\n");
        printf("2. Buscar pelicula\n");
        printf("3. Contar peliculas por genero\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirInverso(videoteca, numPeliculas);
                break;
            case 2:
                buscarPelicula(videoteca, numPeliculas);
                break;
            case 3:
                contarPorGenero(videoteca, numPeliculas);
                break;
            case 0:
                printf("Gracias por usar el programa. ¡Hasta luego!\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

// 3. Captura datos por teclado con scanf
void capturarDatos(pelicula videoteca[], int *numPeliculas) {
    char respuesta;
    printf("\n--- CAPTURA DE DATOS ---\n");
    do {
        printf("Ingrese los datos de la pelicula #%d\n", *numPeliculas + 1);
        printf("Titulo: ");
        scanf(" %[^\n]", videoteca[*numPeliculas].titulo);
        printf("Director: ");
        scanf(" %[^\n]", videoteca[*numPeliculas].director);
        printf("Anio: ");
        scanf("%d", &videoteca[*numPeliculas].anio);
        printf("Genero: ");
        scanf(" %[^\n]", videoteca[*numPeliculas].genero);

        (*numPeliculas)++;

        if (*numPeliculas >= MAX_PELICULAS) {
            printf("Se ha alcanzado el numero maximo de peliculas.\n");
            break;
        }

        printf("¿Desea agregar otra pelicula? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');
}

// 4. Imprime peliculas en orden inverso
void imprimirInverso(pelicula videoteca[], int numPeliculas) {
    if (numPeliculas == 0) {
        printf("No hay peliculas para mostrar.\n");
        return;
    }
    printf("\n--- PELICULAS EN ORDEN INVERSO ---\n");
    for (int i = numPeliculas - 1; i >= 0; i--) {
        printf("Pelicula #%d:\n", i + 1);
        printf("  - Titulo: %s\n", videoteca[i].titulo);
        printf("  - Director: %s\n", videoteca[i].director);
        printf("  - Anio: %d\n", videoteca[i].anio);
        printf("  - Genero: %s\n", videoteca[i].genero);
        printf("------------------------\n");
    }
}

// Búsqueda por año, director o nombre
void buscarPelicula(pelicula videoteca[], int numPeliculas) {
    int opcion;
    printf("\n--- BUSQUEDA DE PELICULAS ---\n");
    printf("1. Buscar por titulo\n");
    printf("2. Buscar por director\n");
    printf("3. Buscar por anio\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    int encontradas = 0;
    char busqueda_str[MAX_TITULO];
    int busqueda_int;

    switch (opcion) {
        case 1:
            printf("Ingrese el titulo a buscar: ");
            scanf(" %[^\n]", busqueda_str);
            for (int i = 0; i < numPeliculas; i++) {
                if (strstr(videoteca[i].titulo, busqueda_str) != NULL) {
                    printf("Pelicula encontrada:\n");
                    printf("  - Titulo: %s\n", videoteca[i].titulo);
                    printf("  - Director: %s\n", videoteca[i].director);
                    printf("  - Anio: %d\n", videoteca[i].anio);
                    printf("  - Genero: %s\n", videoteca[i].genero);
                    encontradas++;
                }
            }
            break;
        case 2:
            printf("Ingrese el director a buscar: ");
            scanf(" %[^\n]", busqueda_str);
            for (int i = 0; i < numPeliculas; i++) {
                if (strstr(videoteca[i].director, busqueda_str) != NULL) {
                    printf("Pelicula encontrada:\n");
                    printf("  - Titulo: %s\n", videoteca[i].titulo);
                    printf("  - Director: %s\n", videoteca[i].director);
                    printf("  - Anio: %d\n", videoteca[i].anio);
                    printf("  - Genero: %s\n", videoteca[i].genero);
                    encontradas++;
                }
            }
            break;
        case 3:
            printf("Ingrese el anio a buscar: ");
            scanf("%d", &busqueda_int);
            for (int i = 0; i < numPeliculas; i++) {
                if (videoteca[i].anio == busqueda_int) {
                    printf("Pelicula encontrada:\n");
                    printf("  - Titulo: %s\n", videoteca[i].titulo);
                    printf("  - Director: %s\n", videoteca[i].director);
                    printf("  - Anio: %d\n", videoteca[i].anio);
                    printf("  - Genero: %s\n", videoteca[i].genero);
                    encontradas++;
                }
            }
            break;
        default:
            printf("Opcion de busqueda invalida.\n");
            return;
    }

    if (encontradas == 0) {
        printf("No se encontraron peliculas con los criterios de busqueda.\n");
    }
}

// Contador por género
void contarPorGenero(pelicula videoteca[], int numPeliculas) {
    if (numPeliculas == 0) {
        printf("No hay peliculas para contar.\n");
        return;
    }

    printf("\n--- CONTEO POR GENERO ---\n");
    // Usamos un arreglo auxiliar para llevar el conteo
    char generosUnicos[MAX_PELICULAS][MAX_GENERO];
    int conteo[MAX_PELICULAS];
    int numGenerosUnicos = 0;

    for (int i = 0; i < numPeliculas; i++) {
        int generoEncontrado = 0;
        for (int j = 0; j < numGenerosUnicos; j++) {
            if (strcmp(videoteca[i].genero, generosUnicos[j]) == 0) {
                conteo[j]++;
                generoEncontrado = 1;
                break;
            }
        }
        if (!generoEncontrado) {
            strcpy(generosUnicos[numGenerosUnicos], videoteca[i].genero);
            conteo[numGenerosUnicos] = 1;
            numGenerosUnicos++;
        }
    }

    for (int i = 0; i < numGenerosUnicos; i++) {
        printf("- %s: %d pelicula(s)\n", generosUnicos[i], conteo[i]);
    }
}

// Validación simple
int validarDatos(int numDirectores, int numPeliculas) {
    if (numDirectores <= 0) {
        printf("El numero de directores no puede ser 0 o -1.\n");
        return 0;
    }
    if (numPeliculas <= 0) {
        printf("La videoteca no puede tener 0 o -1 peliculas.\n");
        return 0;
    }
    printf("Lalidacion de datos exitosa.\n");
    return 1;
}
