#include<stdio.h>

int main(){

// int myNum1[5]={10,6,3,9,2};
// int myNum2[5]={7,13,23,5,9};

int size1;
printf("enter the size of first array : ");
scanf("%d", &size1);

int myNumber1[size1];
printf("enter the first array element :");

for(int i= 0; i<size1; i++){
    scanf("%d", &myNumber1[i]);
}


int size2;
printf("enter the size of second array : ");
scanf("%d", &size2);

int myNumber2[size2];
printf("enter the second array element :");

for(int i= 0; i<size2; i++){
    scanf("%d", &myNumber2[i]);
}

int newSize = size1+size2;

int mergedArray[newSize];

for(int i= 0; i<size1; i++){
    mergedArray[i]=myNumber1[i];
    }
 for(int i=0; i<size2; i++){
    mergedArray[i+size1]=myNumber2[i];
    }
 
//   printf("%d " , mergedArray[0]);
for(int i =0; i<newSize; i++){
    printf("%d" , mergedArray[i]);
}

}