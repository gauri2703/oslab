#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ARRAY_SIZE 100
#define MAX_THREADS 2

int array[MAX_ARRAY_SIZE];
int array_size;
int even_sum = 0;
int odd_sum = 0;

void* sum_even(void* param) {
    for (int i = 0; i < array_size; i++) {
        if (array[i] % 2 == 0) {
            even_sum += array[i];
        }
    }
    return NULL;
}

void* sum_odd(void* param) {
    for (int i = 0; i < array_size; i++) {
        if (array[i] % 2 != 0) {
            odd_sum += array[i];
        }
    }
    return NULL;
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    if (array_size <= 0 || array_size > MAX_ARRAY_SIZE) {
        printf("Invalid array size. Please choose a valid size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }

    pthread_t tid[MAX_THREADS];

    pthread_create(&tid[0], NULL, sum_even, NULL);
    pthread_create(&tid[1], NULL, sum_odd, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Sum of even numbers: %d\n", even_sum);
    printf("Sum of odd numbers: %d\n", odd_sum);

    return 0;
}
