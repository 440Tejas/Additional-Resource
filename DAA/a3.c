#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement Quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random numbers for the array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }
}

int main() {
    // Define array sizes for the experiment
    int sizes[] = {4, 5, 6};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Loop over different array sizes
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int arr[n];

        printf("Choose an option for input of %d elements:\n", n);
        printf("1. Read from file\n");
        printf("2. Generate random numbers\n");
        int option;
        scanf("%d", &option);

        // Input elements based on user's choice
        switch (option) {
            case 1:
                // Read elements from file
                printf("Enter the filename to read elements from: ");
                char filename[100];
                scanf("%s", filename);

                FILE *file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    exit(1);
                }

                printf("Input array: ");
                for (int j = 0; j < n; j++) {
                    fscanf(file, "%d", &arr[j]);
                    printf("%d ", arr[j]);
                }
                printf("\n");

                fclose(file);
                break;
            case 2:
                // Generate random numbers
                generateRandomArray(arr, n);

                printf("Input array: ");
                for (int j = 0; j < n; j++) {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                break;
            default:
                printf("Invalid option.\n");
                exit(1);
        }

        // Record start time
        clock_t start = clock();

        // Sort the array using Quick sort
        quickSort(arr, 0, n - 1);

        // Record end time
        clock_t end = clock();

        // Calculate time taken to sort
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print sorted array
        printf("Sorted array: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        // Print time taken to sort
        printf("Time taken to sort: %f seconds\n\n", cpu_time_used);
    }

    return 0;
}
