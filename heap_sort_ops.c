#include <stdio.h>

// Swap function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Use the swap function here
        heapify(arr, n, largest);
    }
}

void maxheap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Insert a new element into the max-heap
void insert(int arr[], int *n, int value) {
    arr[*n] = value; // Add the new element at the end
    int i = *n;
    (*n)++;
    
    // Bubble up to maintain max-heap property
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]); // Use the swap function here
        i = (i - 1) / 2;
    }
}

// Delete the root (maximum element) from the max-heap
void deleteRoot(int arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty, cannot delete.\n");
        return;
    }

    // Replace root with the last element
    arr[0] = arr[*n - 1];
    (*n)--;
    
    // Heapify from the root to maintain max-heap property
    heapify(arr, *n, 0);
}
void heapsort(int a[],int n)
{
    int i;
    maxheap(a,n);
    for(i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

int main() {
    int arr[10], n = 0, choice, value;
    
    printf("Enter the initial number of elements in the heap: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the heap:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the initial max heap
    maxheap(arr, n);
    printf("Max-heap array:\n");
    printarray(arr, n);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n2. Delete Root\n3. Print Heap\n4.heap sort\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(arr, &n, value);
                printf("Heap after insertion:\n");
                printarray(arr, n);
                break;
            case 2:
                printf("Deleting the root...\n");
                deleteRoot(arr, &n);
                printf("Heap after deletion:\n");
                printarray(arr, n);
                break;
            case 3:
                printf("Current heap:\n");
                printarray(arr, n);
                break;
            case 4:
                printf("sorted array:\n");
                heapsort(arr,n);
                 printarray(arr, n);
                break;
            case 5:
                return 0;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
}
