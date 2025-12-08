def max_recursivo_dc_aux(lista, low, high):
    """
    Función auxiliar recursiva (Divide & Conquer) para encontrar
    el máximo en el sub-arreglo lista[low...high].
    """
    # CASO BASE: El sub-arreglo tiene un solo elemento
    if low == high:
        return lista[low]

    # DIVIDE: Calcula el punto medio
    # Usamos // para asegurar una división entera
    mid = (low + high) // 2

    # CONQUISTA: Llama recursivamente a ambas mitades
    max_izquierda = max_recursivo_dc_aux(lista, low, mid)
    max_derecha = max_recursivo_dc_aux(lista, mid + 1, high)

    # COMBINA: Retorna el mayor de los dos máximos encontrados
    # La función max() simplifica la comparación del pseudocódigo
    return max(max_izquierda, max_derecha)

def max_recursivo(lista):
    """
    Función principal que inicia el proceso recursivo.
    """
    if not lista:
        # Manejo de error si la lista está vacía
        raise ValueError("La lista no puede estar vacía.")
    
    # Llama a la función auxiliar con los límites del arreglo completo
    return max_recursivo_dc_aux(lista, 0, len(lista) - 1)

#  Bloque de Prueba para la Interfaz de Usuario 
try:
    # 1. Ingreso del tamaño de la lista
    n_input = input("Ingresa el tamaño de la lista (debe ser un número entero): ")
    n = int(n_input) 
    
    if n <= 0:
        print("El tamaño de la lista debe ser un entero positivo. \n")
    else:
        lista = []
        print("Ingresa los elementos (uno por uno): \n")
        
        # 2. Ingreso de los elementos
        for i in range(n):
            elemento = int(input(f"Elemento {i+1}: "))
            lista.append(elemento)
        
        # 3. Llamada al algoritmo
        resultado = max_recursivo(lista)
        
        # 4. Impresión del resultado
        print(f"\nLista ingresada: {lista}")
        print("El valor máximo es:", resultado)

except ValueError as e:
    # Manejo de errores de conversión de tipos o lista vacía
    print(f"\nError: {e}. Asegúrate de ingresar números enteros y un tamaño de lista válido.")
except Exception as e:
    # Manejo de cualquier otro error
    print(f"\nOcurrió un error inesperado: {e}")
