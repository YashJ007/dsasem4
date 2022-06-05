#include <stdio.h>

void Prims(int n, int cost[10][10]);

int main(void) {
  int n,cost[10][10];

  printf("Enter no of vertices: ");
  scanf("%d",&n);

  printf("Enter cost matrix: ");
  for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
      printf("cost[%d][%d]: ",i,j);
scanf("%d",&cost[i][j]);
       if(cost[i][j]==0){
        cost[i][j]=999;
      }
}
}
  Prims(n,cost);
}

void Prims(int n, int cost[10][10]){
  int min_cost=0;
  int e=1; //e:edges
  int min,u=1,v=1; //u:path v:vertex
  int visited[10];

  for(int i=1;i<=n;i++){
    visited[i]=0;
  }
  visited[1]=1;
  while(e<n){
    for(int i=1, min=999;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(cost[i][j]<min){
          if(visited[i]==0)
            continue;
          else{
            min = cost[i][j];
            u=i;
            v=j;
          }
        }
      }
      if(visited[u]==0 || visited[v]==0){
        min_cost = min_cost + min;
        printf("%d. edge(%d,%d) & cost = %d\n",e++,u,v,min);
        visited[v]=1;
      }
      cost[u][v]=cost[v][u]=999;
    }
  }
  printf("\nMin cost : %d",min_cost);
}
