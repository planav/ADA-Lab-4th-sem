#include<iostream>
using namespace std;
int s[10],sum,n,d,set[10],count=0,flag=0;


void display(int count)
{
cout<<"{ ";
for(int i=0;i<count;i++)
cout<<set[i]<<" ";
cout<<" }"<<endl;
}

void subset(int sum,int i)
{
if(sum==d)
{
flag=1;
display(count);
return;
}

if(sum>d||i>=n)
{
return;
}
else
{
set[count]=s[i];
count++;
subset(sum+s[i],i+1);
count--;
subset(sum,i+1);
}
}



int main()
{
cout<<"\nEnter the number of items : ";
cin>>n;
cout<<"\nEnter the items : ";
for(int i=0;i<n;i++)
cin>>s[i];
cout<<"\nEnter the sum of items : ";
cin>>d;
subset(0,0);
if(flag==0)
cout<<"\nSum not found !! ";
return 0;
}
