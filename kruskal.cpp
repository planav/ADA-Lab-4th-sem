#include<iostream>
using namespace std;

int ne=1,min_cost=0;
int main()
{
int cost[10][10],visited[10]={0},a,b,u,v,n;
cout<<"\nEnter the number of nodes : ";
cin>>n;
cout<<endl;
cout<<"Enter the nodes : ";
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cin>>cost[i][j];
}
}
for(int i=0;i<=n;i++)
visited[i]=0;

while(ne<n)
{
int min=999;
for(int i=1;i<=n;i++)
{
for(int j=0;j<=n;j++)
{
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
}
}

while(visited[u])
{
u=visited[u];
}
while(visited[v])
{
v=visited[v];
}

if(u!=v)
{
cout<<"\nEdge"<<ne++<<": ("<<a<<","<<b<<") cost : "<<min<<endl;
min_cost+=min;
visited[v]=u;
}


cost[a][b]=cost[b][a]=999;
}
cout<<"The minimum value is : <<"<<min_cost;
return 0;
}
