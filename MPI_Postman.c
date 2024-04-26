#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 100  // Define el tamaño del arreglo como constante

void simpleSort(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    int i;
    double start_time, end_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int len = ARRAY_SIZE;
    int *arr = (int *)malloc(len * sizeof(int));
    int *arr1 = (int *)malloc(len * sizeof(int));

    srand(rank + time(NULL));  // Semilla para rand() con el rango del proceso para diferentes valores aleatorios

    // Llenar automáticamente el array con valores aleatorios
    for (i = 0; i < len; i++) {
        arr[i] = rand() % 100;  // Generar un número aleatorio entre 0 y 99
    }

    MPI_Barrier(MPI_COMM_WORLD);  // Sincronización antes de iniciar el temporizador
    start_time = MPI_Wtime();  // Iniciar temporizador

    int local_len = len / size;
    int *local_arr = (int *)malloc(local_len * sizeof(int));

    MPI_Scatter(arr, local_len, MPI_INT, local_arr, local_len, MPI_INT, 0, MPI_COMM_WORLD);

    // Ordenar array local usando un simple método de ordenación
    simpleSort(local_arr, local_len);

    MPI_Gather(local_arr, local_len, MPI_INT, arr1, local_len, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Ordenamiento final después de recoger los resultados
        simpleSort(arr1, len);
    }

    MPI_Barrier(MPI_COMM_WORLD);  // Sincronización antes de detener el temporizador
    end_time = MPI_Wtime();  // Detener temporizador

    if (rank == 0) {
        printf("Sorted Array:\n");
        for (i = 0; i < len; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        printf("Execution time: %f seconds\n", end_time - start_time);
    }

    free(arr);
    free(arr1);
    free(local_arr);

    MPI_Finalize();

    return 0;
}
