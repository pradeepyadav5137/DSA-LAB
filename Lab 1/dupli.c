#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Repeating elements are: ");
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                printf("%d ", arr[i]);
                break; 
            }
        }
    }

    return 0;
}