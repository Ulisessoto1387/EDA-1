def fibonacci_recursivo(n):
    """
    Calcula el n-ésimo número de Fibonacci usando recursión.
    """
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2)

posiciones = [7, 21, 40, 71, 94]

print(" Secuencia de Fibonacci Recursiva ")
for n in posiciones:
    # Para n=71 y n=94, el cálculo recursivo puro tardará mucho o causará 
    # un error de límite de recursión si no está configurado correctamente.
    # Por eficiencia, usaremos un enfoque iterativo para n > 40.

    if n > 40:
        # Usamos una función iterativa para calcular números grandes 
        a, b = 0, 1
        for _ in range(2, n + 1):
            a, b = b, a + b
        resultado = b
        
    else:
        resultado = fibonacci_recursivo(n)

    print(f"El número en la posición {n} es: {resultado}")
    