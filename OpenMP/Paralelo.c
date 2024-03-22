#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrange(int, int);

#define MAX_SIZE 5000

int array[MAX_SIZE], array1[MAX_SIZE];
int i, j, temp, max, count, maxdigits = 0, c = 0;

int main() {
    int t1, t2, k, t, n = 1;

    // Generar datos aleatoriamente
    srand(time(NULL)); // Semilla para la generación aleatoria

    count = MAX_SIZE; // Establecer el tamaño del array

    printf("Generated array: ");
    for (i = 0; i < count; i++) {
        array[i] = rand() % 1000; // Generar números aleatorios entre 0 y 999
        printf("%d ", array[i]);
        array1[i] = array[i];
    }
    printf("\n");

    // Resto del código permanece igual
    for (i = 0; i < count; i++) {
        t = array[i]; /*first element in t */
        while (t > 0) {
            c++;
            t = t / 10; /* Find MSB */
        }
        if (maxdigits < c)
            maxdigits = c; /* number of digits of a each number */
        c = 0;
    }
    while (--maxdigits)
        n = n * 10;

    for (i = 0; i < count; i++) {
        max = array[i] / n; /* MSB - Dividnng by perticular base */
        t = i;
        for (j = i + 1; j < count; j++) {
            if (max > (array[j] / n)) {
                max = array[j] / n; /* greatest MSB */
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }
    while (n >= 1) {
        for (i = 0; i < count;) {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++)
                ;
            arrange(i, j);
            i = j;
        }
        n = n / 10;
    }
    printf("\nSorted Array (Postman sort) :");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
    printf("\n");

    return 0;
}

/* Function to arrange the of sequence having same base */
void arrange(int k, int n) {
    for (i = k; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array1[i] > array1[j]) {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

