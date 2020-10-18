#include<stdio.h>
#include<ctype.h>
#define infinity 999

// variables used
// n: no of nodes 
// v: input vertex
// cost[v][i] is the cost of going from vertex v to vertex i
// If there is no edge between vertices v and i then cost[v][i] is infinity.
// dist[] is the distance matrix, by storing the cost of vertices from vertex no. 0 to n-1 from the input vertex v.

void dij(int n,int v,int cost[10][10],int dist[])
{
int i,u,count,w,flag[10],min; 
for(i=1;i<=n;i++)
flag[i]=0,dist[i]=cost[v][i]; 
count=2;
while(count<=n)
{
min=99;
for(w=1;w<=n;w++)
if(dist[w]<min && !flag[w])
min=dist[w],u=w;
flag[u]=1;
count++;
for(w=1;w<=n;w++)
if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
dist[w]=dist[u]+cost[u][w];
}
}
void main()
{
int n,v,i,j,cost[10][10],dist[10];

printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the cost matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=infinity;
}
printf("\n Enter the input vertex:");
scanf("%d",&v);
dij(n,v,cost,dist);
printf("\n Shortest path:\n");
for(i=1;i<=n;i++)
if(i!=v) printf("%d->%d,distance=%d\n",v,i,dist[i]);
getchar();
}
