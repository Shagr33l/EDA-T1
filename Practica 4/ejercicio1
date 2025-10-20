#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *arr, *arr2;

    printf("Cantidad de enteros para malloc: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    printf("Valores iniciales con malloc:\n");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Cantidad de enteros para calloc: ");
    scanf("%d", &n);
    arr2 = (int*)calloc(n, sizeof(int));
    printf("Valores iniciales con calloc:\n");
    for (i = 0; i < n; i++) printf("%d ", arr2[i]);
    printf("\n");

    printf("Ingrese %d valores:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr2[i]);

    printf("Nuevo tamaño: ");
    scanf("%d", &m);
    arr2 = (int*)realloc(arr2, m * sizeof(int));
    if (m > n) {
        for (i = n; i < m; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%d", &arr2[i]);
        }
    }

    printf("Valores finales:\n");
    for (i = 0; i < m; i++) printf("%d ", arr2[i]);
    printf("\n");

    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
