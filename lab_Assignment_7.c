#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps[arr[i]]++;
            swaps[arr[minIndex]]++;
        }
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[100] = {0};
    int swaps2[100] = {0};

    bubbleSort(array1, n1, swaps1);
    selectionSort(array2, n2, swaps2);

    printf("array1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: # of times %d is swapped\n", i, array1[i]);
    }
    int totalSwaps1 = 0;
    for (int i = 0; i < n1; i++) {
        totalSwaps1 += swaps1[array1[i]];
    }
    printf("total # of swaps: %d\n\n", totalSwaps1);

    printf("array2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: # of times %d is swapped\n", i, array2[i]);
    }
    int totalSwaps2 = 0;
    for (int i = 0; i < n2; i++) {
        totalSwaps2 += swaps2[array2[i]];
    }
    printf("total # of swaps: %d\n", totalSwaps2);

    return 0;
}
