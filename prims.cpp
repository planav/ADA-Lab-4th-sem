#include<iostream>
using namespace std;

int ne=1,min_cost=0;

int main()
{
int a,b,source,n;
cout<<"\nEnter the number of nodes :";
cin>>n;
cout<<"\nEnter the nodes : ";
int cost[10][10],visited[10]={0};
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cin>>cost[i][j];
}
}
cout<<"\nEnter the starting node : ";
cin>>source;
visited[source]=1;

cout<<"\n Minimum cost spanning tree :";
while(ne<n)
{
int min=999;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
if(cost[i][j]<min)
{
if(visited[i]!=0)
{
min=cost[i][j];
a=i;
b=j;
}
}
}
}

if(visited[a]==0||visited[b]==0)
{
cout<<"\nEdge "<<ne++<<": ("<<a<<","<<b<<") cost : "<<min<<endl;
min_cost=min_cost+min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
cout<<"\nThe minimum cost is : "<<min_cost;
return 0;
}
