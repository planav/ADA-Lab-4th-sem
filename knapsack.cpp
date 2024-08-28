#include<iostream>

using namespace std;

int max(int x,int y)
{
return(x>y)?x:y;
}

int knapsack(int W,int w[],int v[],int n)
{
int i,wt,k[n+1][W+1];
for(i=0;i<=n;i++)
{
for(wt=0;wt<=W;wt++)
{
if(i==0||wt==0)
k[i][wt]=0;
else if(w[i-1]<=wt)
k[i][wt]=max(v[i-1]+k[i-1][wt-w[i-1]],k[i-1][wt]);
else
k[i][wt]=k[i-1][wt];
}
}
return k[n][W];
}

int main()
{
cout<<"Enter the number of items in the knapsack : ";
int n,W,w[100],v[100];
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\nEnter the value and weight of item "<<i+1<<" : ";
cin>>v[i]>>w[i];
}
cout<<"\nEnter the capacity of knapsack : ";
cin>>W;
cout<<"\nthe maximum value that can be obtained is : "<<knapsack(W,w,v,n);
return 0;
}
