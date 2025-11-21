#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL)
        (*inicio)->anterior = nuevo;

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("\n");
        return;
    }

    struct Nodo *temp = inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    while (temp != NULL && temp->valor != valor)
        temp = temp->siguiente;

    if (temp == NULL)
        return;

    if (temp->anterior == NULL)
        *inicio = temp->siguiente;
    else
        temp->anterior->siguiente = temp->siguiente;

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, i;

    printf("Cuantos valores insertar al inicio: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

    recorrerAdelante(inicio);

    printf("Cuantos valores insertar al final: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);

    eliminar(&inicio, valor);

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);

    return 0;
}
