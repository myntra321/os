#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int n) {
    int temp, i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a child process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        // Error occurred while forking
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process sorting...\n");
        bubbleSort(arr, n);
        printf("Child process sorted the array.\n");
    } else {
        // Parent process
        printf("Parent process waiting for the child...\n");
        wait(NULL);
        printf("Parent process sorted the array.\n");
    }	bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
