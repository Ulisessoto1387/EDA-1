//Primer codigo 
#include <stdio.h>
int main(void){
    int n;
    int a[10];
    
    printf ("Dame el tamaño de tu array (No mayor a 10). \n"); 
    scanf ("%d", &n); 
    
    if ((n > 0) && (n < 11)){
    printf ("Ingrese %d números: \n", n);
    for (int i=0; i<n; i++){
        printf ("Elemento %d:",i);
        scanf ("%d", &a[i]); }
    
    printf ("\nLos elementos del array son:");
    for (int i=0; i<n; i++){
        printf ("\n");
        printf ("%d", a[i] ); }
    
    }else {
        printf ("No sabes leer"); 
    }
    
    return 0; 
}



//Segundo codigo 
#include <stdio.h>
int main(void){
    int n,suma=0,resta=0;
    float promedio=0;
    int a[10];
    
    printf ("Dame el tamaño de tu array (No mayor a 10). \n"); 
    scanf ("%d", &n); 
    
    if ((n > 0) && (n < 11)){
    printf ("Ingrese %d números: \n", n);
    for (int i=0; i<n; i++){
        printf ("Elemento %d:",i);
        scanf ("%d", &a[i]); }
    
    printf ("\nLos elementos del array son:");
    for (int i=0; i<n; i++){
        printf ("\n");
        printf ("%d", a[i] ); }
         printf ("\n");
         
    for (int i=0; i<n; i++){
        suma = suma + a[i];}
        printf ("\nEl resultado de la suma es:%d", suma); 
        
        for (int i=0; i<n; i++){
        resta = resta - a[i];}
        printf ("\nEl resultado de la resta es:%d", resta); 
        printf ("\nEl resultado de la resta es igual al de la suma pero en negativo por que empieza en 0 y a partir de hay se le restan los valores del array");
        
        promedio = ((float)suma/n);
        printf ("\nEl promedio de los valores del Array es:%.3f", promedio);
        
         int indicemen=0; int indicemay=0;
         int menor=a[0], mayor=a[0]; 
        
        for (int i=0; i<n; i++){
            if (a[i]<menor){
                menor = a[i];
                indicemen =i;
            }
            
            if (a[i]>mayor){
                mayor = a[i];
                indicemay=i;
            }
        }
        
        printf ("\nEl valor más chico del array es:%d y esta en el indice:%d", menor,indicemen);
        printf ("\nEl valor más grande del array es:%d y esta en el indice:%d", mayor,indicemay);
        
    }else {
        printf ("No sabes leer"); 
    }
    
    return 0; 
}




//Tercer codigo 
#include <stdio.h>

int main (void){
    int n; 
    int a[10];
    
    printf ("Dame el tamaño de tu array (No mayor a 10). \n");
    scanf ("%d", &n);
    
    if ((n > 0) && (n < 11)){
        printf ("Ingrese %d números: \n", n);
        for (int i=0; i<n;i++){
            printf ("Elemento %d:", i);
            scanf ("%d", &a[i]); }
            
            printf ("\nLos elementos del array son:");
            for (int i=0; i<n; i++){
                printf("\n"); 
                printf ("%d", a[i]); }
                
                int copia[10];
                int contador = 0;
                
                for (int i=n-1; i>=0; i--){
                    copia[contador] = a[i]; 
                    contador++; 
                }    
                    printf ("\nEl arreglo invertido es:\n");
                    for (int i=0; i<n; i++){
                        printf ("%d ", copia[i]);
                    }
    }else{
        printf ("No sabes leer."); 
    }
    
    return 0; 
}