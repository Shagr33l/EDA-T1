//Cola circular
#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializar(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Error: Cola llena, no se puede encolar %d\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

void dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: Cola vacía, no se puede desencolar\n");
        return;
    }
    printf("Desencolado: %d\n", c->datos[c->frente]);
    c->frente = (c->frente + 1) % MAX;
    c->size--;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Cola vacía.\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Cola: ");
    if (isEmpty(c)) {
        printf("[vacía]\n");
        return;
    }
    int i, index;
    for (i = 0; i < c->size; i++) {
        index = (c->frente + i) % MAX;
        printf("%d ", c->datos[index]);
    }
    printf("\n");
}

int main() {
    ColaCircular c;
    inicializar(&c);

    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);

    dequeue(&c);
    printQueue(&c);

    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30); // demostrará el reciclaje circular
    printQueue(&c);

    printf("\n--- Preguntas (A) ---\n");
    printf("1. No se desperdician posiciones porque los índices se reciclan con el operador %%.\n");
    printf("2. Cuando el índice final llega al final, vuelve a 0 gracias al módulo.\n");
    printf("3. Si intentas encolar con la cola llena, se muestra error y no se inserta.\n");
    return 0;
}
