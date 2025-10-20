#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void mostrarPila(Pila p) {
    if (p.tope == -1) printf("Pila vacia\n");
    else {
        for (int i = p.tope; i >= 0; i--) printf("%d ", p.datos[i]);
        printf("\n");
    }
}

void push(Pila *p, int valor) {
    if (p->tope == MAX - 1) printf("Pila llena\n");
    else {
        p->datos[++p->tope] = valor;
        mostrarPila(*p);
    }
}

void pop(Pila *p) {
    if (p->tope == -1) printf("Pila vacia\n");
    else {
        printf("Sale: %d\n", p->datos[p->tope--]);
        mostrarPila(*p);
    }
}

void mostrarCola(Cola c) {
    if (c.final < c.frente) printf("Cola vacia\n");
    else {
        for (int i = c.frente; i <= c.final; i++) printf("%d ", c.datos[i]);
        printf("\n");
    }
}

void enqueue(Cola *c, int valor) {
    if (c->final == MAX - 1) printf("Cola llena\n");
    else {
        c->datos[++c->final] = valor;
        mostrarCola(*c);
    }
}

void dequeue(Cola *c) {
    if (c->frente > c->final) printf("Cola vacia\n");
    else {
        printf("Sale: %d\n", c->datos[c->frente++]);
        mostrarCola(*c);
    }
}

int main() {
    Pila p;
    Cola c;
    int n, i, val;

    p.tope = -1;
    printf("Pila inicializada vacia\n");
    printf("Cuantos elementos apilar (max 5): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &val);
        push(&p, val);
    }

    printf("Cuantos elementos desapilar: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) pop(&p);

    c.frente = 0;
    c.final = -1;
    printf("Cola inicializada vacia\n");
    printf("Cuantos elementos encolar (max 5): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &val);
        enqueue(&c, val);
    }

    printf("Cuantos elementos desencolar: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) dequeue(&c);

    printf("Pila -> LIFO\n");
    printf("Cola -> FIFO\n");

    return 0;
}
