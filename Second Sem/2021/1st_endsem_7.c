/*Write a function that can take an array of 10 integers as argument and sort the input array. 
Print the contents of the sorted array in the main program.*/
#include<stdio.h>
void sort(int arr[10]){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
void main(){
    int arr[10];
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}