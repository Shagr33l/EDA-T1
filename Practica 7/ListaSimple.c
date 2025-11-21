//lista simple
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Insertar al inicio
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Recorrer la lista
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Eliminar un nodo por valor
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza, *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente; // mover cabeza
    } else {
        anterior->siguiente = actual->siguiente; // saltar nodo
    }

    free(actual);
    printf("Valor %d eliminado correctamente.\n", valor);
}

// Liberar toda la memoria
void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

// Programa principal
int main() {
    struct Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta un valor: ");
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    recorrer(cabeza);
    printf("¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);
    recorrer(cabeza);

    liberar(cabeza);

    // Preguntas y respuestas
    printf("\n--- Preguntas (Lista Simple) ---\n");
    printf("1. ¿Por qué las listas enlazadas no requieren tamaño fijo?\n");
    printf("   Porque cada nodo se crea dinámicamente con malloc(), no se reserva memoria fija como en los arreglos.\n");
    printf("2. ¿Qué diferencia hay entre mover la cabeza y modificar los punteros internos?\n");
    printf("   Mover la cabeza cambia el inicio de la lista, mientras que modificar punteros internos ajusta conexiones entre nodos intermedios.\n");

    return 0;
}
