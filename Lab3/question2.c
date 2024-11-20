#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global array to store Fibonacci sequence
int *fibonacci;
int n;

// Thread function to generate Fibonacci sequence
void *generate_fibonacci(void *arg) {
    fibonacci[0] = 0;
    if (n > 1) fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of Fibonacci terms>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);//convert string to integer 

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for Fibonacci sequence
    fibonacci = (int *)malloc(n * sizeof(int));

    pthread_t thread;

    // Create the thread to generate the Fibonacci sequence
    pthread_create(&thread, NULL, generate_fibonacci, NULL);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Print the Fibonacci sequence
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(fibonacci);
    return 0;
}

