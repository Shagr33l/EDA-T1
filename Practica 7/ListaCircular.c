//lista circular
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Insertar al inicio en lista circular
void insertarInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = *cabeza;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
}

// Recorrer lista circular
void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *actual = cabeza;
    printf("Lista circular: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(vuelve al inicio)\n");
}

// Eliminar un nodo por valor
void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía, nada que eliminar.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    if (actual == *cabeza) {
        if (*cabeza == *ultimo) {
            *cabeza = NULL;
            *ultimo = NULL;
        } else {
            *cabeza = actual->siguiente;
            (*ultimo)->siguiente = *cabeza;
        }
    } else if (actual == *ultimo) {
        anterior->siguiente = *cabeza;
        *ultimo = anterior;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Valor %d eliminado correctamente.\n", valor);
}

void liberarCircular(struct Nodo **cabeza, struct Nodo **ultimo) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *siguiente;

    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != *cabeza);

    *cabeza = NULL;
    *ultimo = NULL;
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL, *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta un valor: ");
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    recorrerCircular(cabeza);
    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);
    eliminarCircular(&cabeza, &ultimo, eliminarValor);
    recorrerCircular(cabeza);

    liberarCircular(&cabeza, &ultimo);

    return 0;
}
