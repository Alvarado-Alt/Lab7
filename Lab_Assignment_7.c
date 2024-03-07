#include <stdio.h>
#include <stdlib.h>

// Bubble Sort Function
void bubbleSort(int arr[], int n, int swaps[], int *t) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
        
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
        
                // addd to swap counters
                swaps[arr[j]]++;
                (*t)++;
            }
        }
    }
}

// Selection Sort Function
void selectionSort(int arr[], int n, int swaps[], int *t) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        
        // Add to swap counters
        swaps[arr[i]]++;
        (*t)++;
    }
}

// Print output for # of swaps and total # of swaps
void printSwaps(int arr[], int n, int swaps[], int t) {

    // # of swaps per value
    for (int i = 0; i < n; i++) {
        printf("%d: # of times swapped is %d\n", arr[i], swaps[arr[i]]);
    }

    // Total # of swaps
    printf("total # of swaps: %d\n\n", t);
}

int main() {

    // Original arrays
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int *swaps1 = (int *)malloc(100 * sizeof(int));
    int *swaps2 = (int *)malloc(100 * sizeof(int));

    // Initialize swap arrays to zero
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }
    
    int totalSwaps1;
    int totalSwaps2;


    // Bubble Sort print out
    printf("Bubble Sort:\n");
    
    // Sort and print for array 1
    printf("array1:\n");
    bubbleSort(array1, size1, swaps1, &totalSwaps1);
    printSwaps(array1, size1, swaps1, totalSwaps1);
    
    // Sort and print Bubble Sort for array 2
    printf("array2:\n");
    bubbleSort(array2, size2, swaps2, &totalSwaps2);
    printSwaps(array2, size2, swaps2, totalSwaps2);

    // Reset arrays and swaps for selection sort next
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    // Selection Sort print out
    printf("Selection Sort:\n");
    
    // Sort and print for array 1
    printf("array1:\n");
    selectionSort(array1, size1, swaps1, &totalSwaps1);
    printSwaps(array1, size1, swaps1, totalSwaps1);

    // Sort and print for array 2
    printf("array2:\n");
    selectionSort(array2, size2, swaps2, &totalSwaps2);
    printSwaps(array2, size2, swaps2, totalSwaps2);

    // Free memory
    free(swaps1);
    free(swaps2);

    return 0;
}
