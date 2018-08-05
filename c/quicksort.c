int partition(int* arr, int low, int high) {
    int pivot = arr[low]; //TODO
    int i = low, j = high;
    while (i < j) {
        while (arr[j] >= pivot && i < j)
            j--;
        arr[i] = arr[j];
        while (arr[i] < pivot && i < j)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

void recursive_sort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        recursive_sort(arr, low, pi - 1);
        recursive_sort(arr, pi + 1, high);
    }
}

void quicksort(int* arr, int len) {
    recursive_sort(arr, 0, len - 1);
}

#if 1

#include <stdio.h>

int main() {
    int arr[6] = {4, 3, 5, 8, 2, 7};
    quicksort(arr, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
#endif