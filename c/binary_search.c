
int binary_search(int ele, int* arr, int len) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (ele < arr[mid])
            high = mid - 1;
        else if (ele > arr[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

int recursive_search(int ele, int* arr, int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (ele < arr[mid])
        return recursive_search(ele, arr, low, mid - 1);
    else if (ele > arr[mid])
        return recursive_search(ele, arr, mid + 1, high);
    else
        return mid;
}

int recursive_binary_search(int ele, int* arr, int len) {
    return recursive_search(ele, arr, 0, len - 1);
}


#if 1

#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("binary search result: %d\n", binary_search(4, arr, 10));
    printf("recursive binary search result: %d\n", recursive_binary_search(4, arr, 10));

    return 0;
}
#endif