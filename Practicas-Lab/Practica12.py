def fibonacci_bottom_up(n):
    """
    Calcula el n-ésimo número de Fibonacci usando el enfoque Bottom-Up (Iteración).
    """
    if n <= 0:
        return 0
    if n == 1:
        return 1
        
    # Inicializar una tabla (array) para almacenar los resultados
    # dp[i] almacenará F(i)
    dp = [0] * (n + 1)
    dp[1] = 1 # Caso base F(1) = 1
    
    # Calcular iterativamente desde i=2 hasta n
    for i in range(2, n + 1):
        # F(i) = F(i-1) + F(i-2)
        dp[i] = dp[i-1] + dp[i-2]
        
    return dp[n]

# Ejecución de ejemplo
N_bottom_up = 10
print(f"\n## 2. Programación Dinámica (Bottom-Up)")
print(f"El número Fibonacci Bottom-Up para N={N_bottom_up} es: {fibonacci_bottom_up(N_bottom_up)}")


//Segundo codigo 
def fibonacci_top_down(n, memo={}):
    """
    Calcula el n-ésimo número de Fibonacci usando el enfoque Top-Down
    (Recursión con Memoización).
    """
    if n in memo:
        return memo[n]  # Caso 1: Devolver el resultado memoizado
        
    if n <= 0:
        return 0
    if n == 1:
        return 1
    
    # Caso 2: Calcular el resultado y memoizarlo
    resultado = fibonacci_top_down(n - 1, memo) + fibonacci_top_down(n - 2, memo)
    memo[n] = resultado
    
    return resultado

# Ejecución de ejemplo
N_top_down = 10
print(f"## 1. Programación Dinámica (Top-Down)")
print(f"El número Fibonacci Top-Down para N={N_top_down} es: {fibonacci_top_down(N_top_down)}")



//Tercer codigo
def quick_sort(arr, bajo, alto):
    """
    Función principal de QuickSort.
    """
    if bajo < alto:
        # Encontrar el índice de la partición (pivote)
        indice_pivote = particionar(arr, bajo, alto)
        
        # Llamadas recursivas en las sublistas
        # 1. Sublista de la izquierda
        quick_sort(arr, bajo, indice_pivote - 1)
        # 2. Sublista de la derecha
        quick_sort(arr, indice_pivote + 1, alto)

def particionar(arr, bajo, alto):
    """
    Función que selecciona un pivote y mueve todos los elementos menores a la 
    izquierda del pivote y los mayores a la derecha.
    Devuelve el índice final del pivote.
    """
    pivote = arr[alto]  # Elegir el último elemento como pivote (ejemplo simple)
    i = bajo - 1        # Índice del elemento más pequeño

    for j in range(bajo, alto):
        # Si el elemento actual es más pequeño o igual al pivote
        if arr[j] <= pivote:
            i = i + 1
            # Intercambiar arr[i] y arr[j]
            arr[i], arr[j] = arr[j], arr[i]
            
    # Colocar el pivote en su posición correcta (entre los menores y los mayores)
    arr[i + 1], arr[alto] = arr[alto], arr[i + 1]
    return i + 1

# Ejecución de ejemplo
lista_desordenada = [10, 7, 8, 9, 1, 5]
n = len(lista_desordenada)
print(f"\n## 3. Divide y Vencerás (QuickSort)")
print(f"Lista desordenada inicial: {lista_desordenada}")

quick_sort(lista_desordenada, 0, n - 1)

print(f"Lista ordenada (QuickSort): {lista_desordenada}")
