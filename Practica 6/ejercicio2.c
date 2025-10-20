//Deque
#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializar(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado.\n");
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == MAX;
}

int rear(Deque *d) {
    return (d->front + d->size - 1 + MAX) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: Deque lleno\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}

void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: Deque lleno\n");
        return;
    }
    int pos = (d->front + d->size) % MAX;
    d->datos[pos] = valor;
    d->size++;
}

void delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: Deque vacío\n");
        return;
    }
    printf("Eliminado del frente: %d\n", d->datos[d->front]);
    d->front = (d->front + 1) % MAX;
    d->size--;
}

void delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: Deque vacío\n");
        return;
    }
    printf("Eliminado del final: %d\n", d->datos[rear(d)]);
    d->size--;
}

int peek_front(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque vacío.\n");
        return -1;
    }
    return d->datos[d->front];
}

int peek_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque vacío.\n");
        return -1;
    }
    return d->datos[rear(d)];
}

void printDeque(Deque *d) {
    printf("Deque: ");
    if (isEmpty(d)) {
        printf("[vacío]\n");
        return;
    }
    for (int i = 0; i < d->size; i++) {
        int index = (d->front + i) % MAX;
        printf("%d ", d->datos[index]);
    }
    printf("\n");
}

int main() {
    Deque d;
    inicializar(&d);

    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);
    printDeque(&d);

    delete_front(&d);
    delete_rear(&d);
    printDeque(&d);

    insert_front(&d, 50);
    insert_rear(&d, 60);
    printDeque(&d);

    printf("\n--- Reflexión (B) ---\n");
    printf("1. El deque permite insertar/eliminar por ambos extremos, la cola circular solo por uno.\n");
    printf("2. Permite simular FIFO (cola normal) y LIFO (pila).\n");
    printf("3. Se usa en programación de tareas, buffers y navegación (ej. historial del navegador).\n");
    return 0;
}
