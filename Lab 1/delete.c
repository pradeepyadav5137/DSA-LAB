#include<stdio.h>

int main(){

int size;
printf("enter the size of the array :");
scanf("%d" , &size);
int arr[size];
printf("enter the array element :");

for(int i=0; i<size; i++){
    scanf("%d" , &arr[i]);

}
int index;
printf("enter the index to delete: ");
scanf("%d" ,&index);


if(index >=0 && index < size){

for(int i = index ; i < size-1; i++){
    arr[i]= arr[i+1];
}
 size= size-1;

for(int i=0; i< size; i++){
    printf("%d", arr[i]);
}


}
else{
    printf("invalid index \n");
}

    return 0;
}