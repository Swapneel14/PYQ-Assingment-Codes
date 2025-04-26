#include<stdio.h>
 int large(int r,int c,int mat[r][c]){
    int max= mat[0][0];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]>=max){
                max= mat[i][j];

            }
        }
    }
    return max;

 }
 void main(){
    int r,c,ans;
    printf("Enter the no. of Rows: ");
    scanf("%d",&r);
    printf("Enter the no. of Col: ");
    scanf("%d",&c);
    int mat[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    ans= large(r,c,mat);
    printf("The largest is: %d",ans);
 }