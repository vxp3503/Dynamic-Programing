#include<bits/stdc++.h>
using namespace std;
int knapasack(int cap,int n,int w[],int value[])
{    
    int dp[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(w[i-1]<=j)
            {
                dp[i][j]=  max(dp[i-1][j-w[i-1]]+value[n-1],dp[i-1][j]);
            }
            else    
            dp[i][j]=dp[i-1][j];
        }
    }
    // else if(w[n-1]<=cap)
    // {
    //     return  max(knapasack(cap-w[n-1],n-1,w,value)+value[n-1],knapasack(cap,n-1,w,value));
    // }
    // else
    // return knapasack(cap,n-1,w,value);
    return dp[n][cap];
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
    cout<<endl<<"Enter the capacity of bag";
    int cap;
    cin>>cap;
    cout<<knapasack(cap,n,w,value);
}