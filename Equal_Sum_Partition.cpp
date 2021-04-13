#include<bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<sum;i++)
    {
        dp[0][sum]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
bool equal_sum_partition(int arr[],int n)
{
    int Sum=0;
    for(int i=0;i<n;i++)
    {
        Sum=Sum+arr[i];
    }
    if(Sum%2!=0)
    {
        return false;
    }
    else
    return subset_sum(arr,n,Sum/2);
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
    cout<<equal_sum_partition(arr,n);
}