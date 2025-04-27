/*1
  2 3
  4 5 6
  7 8 9 10
  --Print This Pattern*/
  #include<stdio.h>
  void main(){
    int r=4;
    int j=1;
    int k=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",k);
            k++;
        }
        printf("\n");
    }
  }
