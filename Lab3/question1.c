#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables to store results
double average = 0.0;
int minimum = 0;
int maximum = 0;

// Global array to store the input numbers
int *numbers;
int num_count;

// Function to calculate the average
void *calculate_average(void *arg) {
    double sum = 0.0;
    
    for (int i = 0; i < num_count; i++) {
        sum += numbers[i];
    }

    average = sum / num_count;
    pthread_exit(NULL);
}

// Function to calculate the minimum value
void *calculate_minimum(void *arg) {
    minimum = numbers[0];
    
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    
    pthread_exit(NULL);
}

// Function to calculate the maximum value
void *calculate_maximum(void *arg) {
    maximum = numbers[0];
    
    for (int i = 1; i < num_count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  
    // Convert command-line arguments to integers
    num_count = argc - 1;
    numbers = (int *)malloc(num_count * sizeof(int));
    
    for (int i = 0; i < num_count; i++) {
        numbers[i] = atoi(argv[i + 1]);//string to interger conversion
    }

    // Declare thread identifiers
    pthread_t avg_thread, min_thread, max_thread;

    // Create threads
    pthread_create(&avg_thread, NULL, calculate_average, NULL);
    pthread_create(&min_thread, NULL, calculate_minimum, NULL);
    pthread_create(&max_thread, NULL, calculate_maximum, NULL);

    // Wait for all threads to finish
    pthread_join(avg_thread, NULL);
    pthread_join(min_thread, NULL);
    pthread_join(max_thread, NULL);

    // Output the results
    printf("A. The average value is %.2f\n", average);
    printf("B. The minimum value is %d\n", minimum);
    printf("C. The maximum value is %d\n", maximum);

    // Free the dynamically allocated memory
    free(numbers);

    return 0;
}
