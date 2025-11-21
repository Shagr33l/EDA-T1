#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    nuevo->valor = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("\n");
        return;
    }

    struct Nodo *temp = inicio;
    do {
        printf("%d ", temp->valor);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL)
        return;

    struct Nodo *temp = *inicio;

    do {
        if (temp->valor == valor)
            break;
        temp = temp->siguiente;
    } while (temp != *inicio);

    if (temp->valor != valor)
        return;

    if (temp->siguiente == temp) {
        free(temp);
        *inicio = NULL;
        return;
    }

    if (temp == *inicio)
        *inicio = temp->siguiente;

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    free(temp);
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, i;

    printf("Cuantos valores insertar: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
    }

    recorrerCircular(inicio);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);

    eliminarCircular(&inicio, valor);

    recorrerCircular(inicio);

    return 0;
}
