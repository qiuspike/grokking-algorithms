
int recursive_sum(int* arr, int len) {
    if (len == 0)
        return 0;
    return arr[0] + recursive_sum(&arr[1], len - 1);
}

#if 1
#include <stdio.h>
int main() {
    int arr[3] = {2, 4, 6};
    printf("sum of arr: %d\n", recursive_sum(arr, 3));
}
#endif