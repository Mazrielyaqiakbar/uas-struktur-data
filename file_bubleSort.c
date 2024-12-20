#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 10000

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int arr[MAX_ELEMENTS], n = 0, i;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read data from file
    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }

    // Sort the array
    bubbleSort(arr, n);

    // Write sorted data back to the file
    rewind(fp);
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
    printf("File sorted successfully.\n");

    return 0;
}