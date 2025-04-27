/*Sum of The Diagonal Elements*/
#include<stdio.h>
int sum(int r, int arr[r][r]){
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
             if(i==j||i+j==r-1){
                sum=sum+arr[i][j];
             }
        }
    }
  
    return sum;
}
void main(){
    int n;
    printf("Enter the dimension of matrix");
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int ans = sum(n,arr);
    printf("The sum is : %d",ans);
}
