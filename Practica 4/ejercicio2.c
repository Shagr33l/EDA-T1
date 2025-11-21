#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr2;

    printf("¿Cuántos enteros deseas almacenar con calloc? ");
    scanf("%d", &n);

    arr2 = (int*) calloc(n, sizeof(int));

    if (arr2 == NULL) {
        printf("Error: no se pudo reservar memoria.\n");
        return 1;
    }

    printf("\nValores iniciales con calloc (ceros):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);  
    }
    printf("\n");

    printf("\nIngresa %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("\nIngresa el nuevo tamaño del arreglo: ");
    scanf("%d", &m);

    int *temp = realloc(arr2, m * sizeof(int));

    if (temp == NULL) {
        printf("Error: realloc falló. No se cambia el tamaño.\n");
        free(arr2);
        return 1;
    }

    arr2 = temp;

    if (m > n) {
        printf("Ingresa los valores adicionales:\n");
        for (int i = n; i < m; i++) {
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nValores finales del arreglo:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
