#include <stdlib.h>
#include <pthread.h>

#define N 100  // Adjust the size of the prime_arr array as needed
#define MAX_THREADS 4

int prime_arr[N] = {0};

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void* printprime(void* ptr) {
    int i = (int)(long long int)ptr;
    while (i < N) {
        if (is_prime(i)) {
            prime_arr[i] = 1;
        }
        i += MAX_THREADS;
    }
    return NULL;
}

int main() {
    pthread_t tid[MAX_THREADS] = {0};
    int count = 0;
    printf("Enter starting and ending\n");
    int st, en;
    scanf("%d %d", &st, &en);

    if (en > N) {
        printf("The range exceeds the limit (N=%d). Please adjust N accordingly.\n", N);
        return 1;
    }

    for (count = 0; count < MAX_THREADS; count++) {
        pthread_create(&tid[count], NULL, printprime, (void*)(long long int)(st + count));
    }
    printf("\n");
    for (count = 0; count < MAX_THREADS; count++) {
        pthread_join(tid[count], NULL);
    }

    printf("Prime numbers in the range [%d, %d]:\n", st, en);
    for (count = st; count <= en; count++) {
        if (prime_arr[count] == 1) {
            printf("%d ", count);
        }
    }
    printf("\n");

    return 0;
}