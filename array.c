#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void insert(int arr[], int datum, int index, int *n)
{
    int i;
    for (i = *n; i >= index; i--)
    {
        arr[i] = arr[i - 1];
    }
    (*n)++;
    arr[index] = datum;
}

int searchElement(int arr[], int element, int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            flag = 1;
            printf("element found at the index %d in the array ", i);
            return i;
        }
    }
    if (!flag)
    {
        printf(" Element not found in the array ");
    }
}

void deleteByIndex(int arr[], int index, int *n)
{

    for (int i = index; i < *n; i++)
    {

        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionsort(int arr[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j= i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}

void selectionsort( int arr[], int n){
      int index, i, j, temp;
      for(i=0; i<n-1; i++){
        index =i ;
        for(j=i+1; j<n ; j++){
            if(arr[j] < arr[index])
            index = j;
        }
         temp = arr[i];
            arr[i]= arr[index];
            arr[index] = temp;
      }

}

int main()
{

    int choice;
    int n, i, datum, index;
    int arr[10];
    printf("please enter the size of the array :");
    scanf("%d", &n);

    printf("enter the element in tha array :");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\n MENU\n: ");
        printf("1. print array  \n");
        printf("2. insert element \n");
        printf("3. search element \n");
        printf("4. delete element by index \n");
        printf("5. delete element by value \n");
        printf("6. sort array by bubble sort \n");
        printf("7. sort array by insertation sort \n");
        printf("8. sort array by selection sort \n");
        printf("9. add element in sorted array by value \n");
        printf("10. exit");

        printf(" enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printArray(arr, n);
            break;

        case 2:
            printf("please enter the index and the number :");
            scanf("%d %d", &index, &datum);
            insert(arr, datum, index, &n);
            break;
        case 3:
            printf("enter element to search in the array : ");
            scanf("%d", &datum);
            searchElement(arr, datum, n);
            break;
        case 4:
            printf("enter the index to delete number : ");
            scanf("%d", &index);
            // while (1)
            // {
            //     if (index < 0 || index > n)
            //         printf("invalid index please enter correct index to delete");
            //     else
            //         exit(0);
            // }
            deleteByIndex(arr, index, &n);
            break;
        case 5:
            printf("Enter the value to delete :");
            scanf("%d", &datum);
            index = searchElement(arr, datum, n);
            deleteByIndex(arr, index, &n);
            break;
        case 6:
            bubblesort(arr, n);
            break;
        case 7:
            insertionsort(arr, n);
            break;
        case 8: selectionsort( arr , n);
                break;
        // case 9: display();
        //         break;
        case 10:
            exit(0);
            break;
        default:
            printf("enter valid choice: ");
        }
    }
}