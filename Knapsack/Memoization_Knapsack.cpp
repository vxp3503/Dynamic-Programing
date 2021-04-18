#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int knapasack(int cap,int n,int w[],int value[])
{
    if(n==0||w==0)
    {
        return 0;
    }
    if(dp[n][cap]!=-1)
    {
        return dp[n][cap];
    }
    else if(w[n-1]<=cap)
    {
        return dp[n][cap]= max(knapasack(cap-w[n-1],n-1,w,value)+value[n-1],knapasack(cap,n-1,w,value));
    }
    else
    return dp[n][cap]=knapasack(cap,n-1,w,value);
}
int main()
{
    int n;
    cout<<"Enter no. of items";
    cin>>n;
    int value[n];
    int w[n];
    cout<<"Enter weight of items";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<endl<<"Enter the capacity of bag";
    int cap;
    cin>>cap;
    cout<<knapasack(cap,n,w,value);
}



//Recursion
// int knapasack(int cap,int n,int w[],int value[])
// {
//     if(n==0||w==0)
//     {
//         return 0;
//     }
//     else if(w[n-1]<=cap)
//     {
//         return  max(knapasack(cap-w[n-1],n-1,w,value)+value[n-1],knapasack(cap,n-1,w,value));
//     }
//     else
//     return knapasack(cap,n-1,w,value);
// }
