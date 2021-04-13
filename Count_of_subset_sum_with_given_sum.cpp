#include<bits/stdc++.h>
using namespace std;
int equal_sum_partition(int arr[],int n,int Sum)
{
    int dp[n+1][Sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for (int i = 1; i <=Sum; i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=Sum;j++)
        {
            if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][Sum];
}
int main()
{
    cout<<"Enter the no. of elements";
    int n;
    cin>>n;
    cout<<"Enter the elements";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Sum";
    int Sum;
    cin>>Sum;
    cout<<equal_sum_partition(arr,n,Sum);
}