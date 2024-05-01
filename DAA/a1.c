#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = low - 1;
 for (int j = low; j < high; j++) {
 if (arr[j] <= pivot) {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]);
 return i + 1;
}
// Function to implement Quick sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// Function to generate random numbers and fill the array
void generateRandomArray(int arr[], int n) {
 for (int i = 0; i < n; i++) {
 arr[i] = rand() % 1000; // generating random numbers between 0 and 999
 }
}
int main() {
 int n;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int *arr = (int *)malloc(n * sizeof(int));
 if (arr == NULL) {
 printf("Memory allocation failed.\n");
 return 1;
 }
 // Generating random array
 generateRandomArray(arr, n);
 // Sorting and measuring time
 clock_t start, end;
 start = clock();
 quickSort(arr, 0, n - 1);
 end = clock();
 double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
 printf("Sorted array:\n");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 printf("Time taken: %f seconds\n", time_taken);
 free(arr);
 return 0;
}
