

#include <stdio.h>

int main() {
   

int size;
printf("enter the size of  array : ");
scanf("%d", &size);
int arr[size];
printf("enter the element of array :");

for(int i=0 ; i<size; i++ ){
  scanf("%d", &arr[i]);
}
int index;
printf("enter the index where we have to add number :");
scanf("%d" , &index);
int newElement;
printf("enter the number :");
scanf("%d", &newElement);

  // Check if the index is valid
    if (index >= 0 && index <= size) {
        // Shift elements to the right to make room for the new element
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert the new element at the specified index
        arr[index] = newElement;
         size++;
       
       printf("Array after adding the new element: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid index\n");
    }

    return 0;
}