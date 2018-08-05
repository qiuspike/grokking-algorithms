
void selection_sort(int* arr, int len) {
    if (len <= 0) return;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


#if 1

#include <stdio.h>

int main() {
    int arr[10] = {6, 3, 1, 9, 3, 4, 6, 8, 12, 20};
    selection_sort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
#endif