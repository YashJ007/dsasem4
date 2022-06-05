#include <stdio.h>


int arr[100];
int min,max,min1,max1;
void minmax(int i, int j);

int main(void) {
  int n;
 printf("Enter the no of vertices: ");
  scanf("%d",&n);

  for(int i=1;i<=n;i++){
    printf("A[%d]:",i);
    scanf("%d",&arr[i]);
  }
  min=arr[0];
  max=arr[0];
  minmax(1,n);
  // printf("Min : %d, Max : %d\n",min,max);
  }

void minmax(int i,int j){
  int min1,max1,mid;
  if(i==j){
    min = max = arr[i];
  }
  else if (i == j-1){
    if(arr[i]>arr[j]){
      max = arr[i];
      min = arr[j];
    }
    else{
      max = arr[j];
      min = arr[i];
    }
  }
  else{
    mid = (i+j)/2;
    minmax(i,mid);
    min1=min;
    max1=max;
    minmax((mid+1),j);
    if(min>min1){
      min=min1;
    }
    if(max<max1){
      max=max1;
    }
     // minmax((mid+1),j,min,max);
  }
   printf("Min : %d, Max : %d\n",min,max);
}
