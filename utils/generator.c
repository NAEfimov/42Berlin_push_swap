#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RANGE 500  // Define the maximum range for random numbers

// Function to check if a number already exists in the array
int exists_in_array(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;  // Number already exists
        }
    }
    return 0;  // Number does not exist
}

// Function to generate n unique random numbers
void generate_unique_random_numbers(int *arr, int n) {
    int count = 0;
    while (count < n) {
        int num = rand() % MAX_RANGE;// - (MAX_RANGE / 2);  // Generate random number in range [0, MAX_RANGE)
        if (!exists_in_array(arr, count, num)) {
            arr[count] = num;  // Add number if it is unique
            count++;
        }
    }
}

int main(int argc, char *argv[]) {
    int n;

    // Ask the user for the number of random integers to generate
    // printf("Enter the number of random integers to generate: ");
    // scanf("%d", &n);
    if (argc != 2)
	    return 1;
    n = atoi(argv[1]);


    // Allocate memory for the array to store n random numbers
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate unique random numbers
    generate_unique_random_numbers(arr, n);

    // Open the file "arg" to write the array
    FILE *file = fopen("arg", "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file!\n");
        free(arr);
        return 1;
    }

    // Write the array to the file as a string of integers
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d", arr[i]);
        if (i < n - 1) {
            fprintf(file, " ");  // Add space between integers
        }
    }
    fprintf(file, "\n");

    // Close the file
    fclose(file);

    printf("Array written to file 'arg'.\n");

    // Free allocated memory
    free(arr);

    return 0;
}
