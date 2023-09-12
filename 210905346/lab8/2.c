#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* summation(void* param) {
    int* arr = (int*)param;
    int sum = 0;
    int n = arr[0];

    for (int i = 1; i <= n; i++) {
        if (arr[i] >= 0) { // Check for non-negative numbers
            sum += arr[i];
        }
    }

    int* result = (int*)malloc(sizeof(int)); // Allocate memory for the result
    *result = sum;
    
    pthread_exit(result); // Use pthread_exit to return the result
}

int main(int argc, char const *argv[]) {
    int n;

    printf("Enter the no. of numbers : \n");
    scanf("%d", &n);

    int* arr = (int*)malloc((n + 1) * sizeof(int));

    arr[0] = n;

    printf("Enter the numbers : \n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    int* answer;
    pthread_t thread;
    pthread_create(&thread, 0, &summation, (void*)arr);
    pthread_join(thread, (void**)&answer);

    printf("Summation of non-negative numbers = %d\n", *answer);

    free(arr);
    free(answer); // Free the allocated memory for the result

    return 0;
}
