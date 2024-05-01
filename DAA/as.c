#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n) {
 int i, j, min_idx;
 for (i = 0; i < n - 1; i++) {
 min_idx = i;
 for (j = i + 1; j < n; j++) {
 if (arr[j] < arr[min_idx]) {
 min_idx = j;
 }
 }
 // Swap the found minimum element with the first element
 int temp = arr[min_idx];
 arr[min_idx] = arr[i];
 arr[i] = temp;
 }
}
double measureTime(int arr[], int n) {
 clock_t start, end;
 double time_taken;
 start = clock();
 selectionSort(arr, n);
 end = clock();
 time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
 return time_taken;
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
 printf("Enter the elements:\n");
 for (int i = 0; i < n; i++) {
     scanf("%d", &arr[i]);
 }
 double time_taken = measureTime(arr, n);
 printf("Sorted array:\n");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 printf("Time taken: %f seconds\n", time_taken);
 free(arr);
 return 0;
}
