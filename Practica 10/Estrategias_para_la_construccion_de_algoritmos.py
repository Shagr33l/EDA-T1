# Fuerza bruta para contraseñas numéricas
import itertools
import time

def fuerza_bruta(digitos, objetivo):
    inicio = time.time()
    for clave in itertools.product("0123456789", repeat=digitos):
        intento = "".join(clave)
        if intento == objetivo:
            return intento, time.time() - inicio

# Greedy (ejemplo: cambio de monedas)
def greedy_cambio(cantidad, denom):
    resultado = []
    for d in denom:
        if cantidad >= d:
            num = cantidad // d
            resultado.append([d, num])
            cantidad -= num * d
    return resultado

# Insertion Sort
def insertion_sort(lista):
    for i in range(1, len(lista)):
        actual = lista[i]
        j = i - 1
        while j >= 0 and lista[j] > actual:
            lista[j+1] = lista[j]
            j -= 1
        lista[j+1] = actual
    return lista

# Pruebas fuerza bruta
print(fuerza_bruta(4, "1234"))
print(fuerza_bruta(8, "12345678"))
print(fuerza_bruta(10, "1029384756"))

# Prueba greedy
print(greedy_cambio(98, [50, 20, 5, 1]))

# Prueba insertion sort
print(insertion_sort([9, 5, 2, 7, 1, 3]))

