import time
import random

def merge(a, b):
    r = []
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            r.append(a[i])
            i += 1
        else:
            r.append(b[j])
            j += 1
    r.extend(a[i:])
    r.extend(b[j:])
    return r

def top_down(lista):
    if len(lista) <= 1:
        return lista
    m = len(lista)//2
    iz = top_down(lista[:m])
    de = top_down(lista[m:])
    return merge(iz, de)

def bottom_up(lista):
    w = 1
    n = len(lista)
    r = [[x] for x in lista]
    while w < n:
        t = []
        for i in range(0, n, w*2):
            a = r[i:i+w]
            b = r[i+w:i+w*2]
            a = a[0] if a else []
            b = b[0] if b else []
            t.append(merge(a, b))
        r = t
        w *= 2
    return r[0]

def quicksort(lista):
    if len(lista) <= 1:
        return lista
    p = lista[len(lista)//2]
    iz = [x for x in lista if x < p]
    me = [x for x in lista if x == p]
    de = [x for x in lista if x > p]
    return quicksort(iz) + me + quicksort(de)

datos = [100, 300, 500, 800, 1000, 1500, 2000]

tiempo_td = []
tiempo_bu = []
tiempo_qs = []

for n in datos:
    lista = [random.randint(1, 99999) for _ in range(n)]

    a = time.time()
    top_down(lista)
    tiempo_td.append(time.time() - a)

    a = time.time()
    bottom_up(lista)
    tiempo_bu.append(time.time() - a)

    a = time.time()
    quicksort(lista)
    tiempo_qs.append(time.time() - a)

print("Tiempos parciales en TOP-DOWN:", tiempo_td)
print("Tiempos parciales en BOTTOM-UP:", tiempo_bu)
print("Tiempos parciales en QUICK SORT:", tiempo_qs)

print("\nTiempo total TOP-DOWN:", sum(tiempo_td))
print("Tiempo total BOTTOM-UP:", sum(tiempo_bu))
print("Tiempo total QUICK SORT:", sum(tiempo_qs))
