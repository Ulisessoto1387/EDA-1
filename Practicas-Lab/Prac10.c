//Primer codigo 
import itertools
import time

def fuerza_bruta_numerica(contrasena_objetivo):
    """
    Intenta adivinar una contraseña numérica de longitud N usando fuerza bruta.
    """
    longitud = len(contrasena_objetivo)
    caracteres = '0123456789'
    intentos = 0
    
    print(f"Iniciando ataque de Fuerza Bruta para una contraseña de {longitud} dígitos...")
    start_time = time.time()

    # itertools.product genera el producto cartesiano (todas las combinaciones)
    for intento_tupla in itertools.product(caracteres, repeat=longitud):
        intento = "".join(intento_tupla)
        intentos += 1
        
        # Opcional: Mostrar algunos intentos para ver el progreso (descomentar si la longitud es pequeña)
        # if intentos % 1000 == 0:
        #     print(f"Intento: {intentos}, Probando: {intento}")
            
        if intento == contrasena_objetivo:
            end_time = time.time()
            tiempo_total = end_time - start_time
            print(f"\n¡Contraseña encontrada!")
            print(f"Resultado: {intento}")
            print(f"Intentos realizados: {intentos}")
            print(f"Tiempo total: {tiempo_total:.4f} segundos")
            return intento

    print("\nContraseña no encontrada (esto no debería pasar si la longitud es correcta).")
    return None

# --- Ejecución de ejemplo ---
contrasena_4_digitos = "8150"
fuerza_bruta_numerica(contrasena_4_digitos)



//Segundo codigo 
import itertools
import time

def fuerza_bruta_limitada(contrasena_objetivo, limite_intentos=None):
    """
    Intenta adivinar una contraseña numérica.
    Incluye un límite de intentos opcional para evitar ejecuciones muy largas.
    """
    longitud = len(contrasena_objetivo)
    caracteres = '0123456789'
    intentos = 0
    encontrada = False
    
    # 1. Calcular el espacio total para estimar
    espacio_claves = 10**longitud
    
    print(f" Ataque de Fuerza Bruta ")
    print(f"Longitud objetivo: {longitud} dígitos")
    print(f"Espacio de claves total: {espacio_claves:,} combinaciones")
    if limite_intentos:
        print(f"Límite de intentos establecido para la simulación: {limite_intentos:,}")

    start_time = time.time()
    
    # Generador de combinaciones
    generador = itertools.product(caracteres, repeat=longitud)

    for intento_tupla in generador:
        intento = "".join(intento_tupla)
        intentos += 1
        
        # 2. Verificar la contraseña
        if intento == contrasena_objetivo:
            encontrada = True
            break
            
        # 3. Aplicar límite de intentos
        if limite_intentos is not None and intentos >= limite_intentos:
            break

    end_time = time.time()
    tiempo_total = end_time - start_time
    print("\n Resultados")

    if encontrada:
        print(f"¡Contraseña encontrada!")
        print(f"Resultado: {intento}")
    else:
        print(f"Simulación detenida.")
        print(f"La contraseña '{contrasena_objetivo}' NO fue encontrada en este intento/límite.")
        
    print(f"Intentos realizados: {intentos:,}")
    print(f"Tiempo total: {tiempo_total:.4f} segundos")

    if tiempo_total > 0 and not encontrada:
        # Estimar la velocidad del sistema
        intentos_por_segundo = intentos / tiempo_total
        tiempo_estimado_total_seg = espacio_claves / intentos_por_segundo
        tiempo_estimado_total_dias = tiempo_estimado_total_seg / (60 * 60 * 24)
        
        print("\n Estimación de Tiempo")
        print(f"Velocidad de ataque: {intentos_por_segundo:,.0f} intentos/segundo")
        
        if tiempo_estimado_total_dias >= 1:
            print(f"Tiempo estimado para probar {espacio_claves:,} combinaciones: ¡**{tiempo_estimado_total_dias:.2f} días**!")
        elif tiempo_estimado_total_seg >= 3600:
             print(f"Tiempo estimado para probar {espacio_claves:,} combinaciones: **{tiempo_estimado_total_seg / 3600:.2f} horas**")
        else:
             print(f"Tiempo estimado para probar {espacio_claves:,} combinaciones: **{tiempo_estimado_total_seg:.2f} segundos**")


#                             PRUEBA DE 8 DÍGITOS
print("\n")
print("             INICIANDO PRUEBA PARA 8 DÍGITOS")
contrasena_8_digitos = "00001234" # Una contraseña temprana para terminar rápido
# Usamos un límite alto para tener una buena estimación de velocidad
fuerza_bruta_limitada(contrasena_8_digitos, limite_intentos=10_000_000) 


#                             PRUEBA DE 10 DÍGITOS
print("\n")
print("             INICIANDO PRUEBA PARA 10 DÍGITOS")
contrasena_10_digitos = "0000000009" # Una contraseña temprana
# Un límite pequeño, solo para calcular la velocidad y hacer la estimación
fuerza_bruta_limitada(contrasena_10_digitos, limite_intentos=1_000_000)