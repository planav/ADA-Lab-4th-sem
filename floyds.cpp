#include<iostream>
using namespace std;

int min_val(int a,int b)
{
if(a<b)
{
return a;
}
else
return b;
}

void floyds(int a[10][10],int p[10][10],int n)
{
int i,k,j;
for(int k=0;k<n;k++)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
a[i][j]=min_val(a[i][j],a[i][k]+a[k][j]);
}
}
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}
}
int main()
{
int a[10][10],p[10][10],n;
cout<<"\nEnter the size of matrix : ";
cin>>n;
cout <<"\nEnter the matrix elements : ";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>p[i][j];
}
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
a[i][j]=p[i][j];
}
}
cout<<"\nThe matrix input is : \n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<endl;
}

cout<<"\n Solution Matrix is : \n";
floyds(a,p,n);
return 0;
}
