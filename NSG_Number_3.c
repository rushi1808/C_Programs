#include <stdio.h>
void findNGE(int arr[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        int next = -1;
        int j;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break;
            }
        }
        printf("%d -> %d\n", arr[i], next);
    }
}
int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    findNGE(arr, n);
    return 0;
}