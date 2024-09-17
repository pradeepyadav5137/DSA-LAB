#include<stdio.h>

int main(){

// int myNumbrs[]= {10,6,7,3,11};
int size;
int myNumber[size];
printf("enter the size of array : ");
scanf("%d", &size);

printf("enter the array element :");

for(int i= 0; i<size; i++){
    scanf("%d", &myNumber[i]);
}


int sum= 0;

for(int i= 0; i<size; i++){
    sum += myNumber[i];
}

printf("%d", sum);

}





