#include<stdio.h>
int maximum(int arr[],int n){
    int max= arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>=max){
            max=arr[i];
        }
    }
    return max;

}
void main(){
    int n;
    printf("Enter Size of Array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = maximum(arr,n);
    printf("%d",ans);
}
