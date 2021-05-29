#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int arr[],int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        dp[i][j]=INT_MAX;
        for(int k=i;k<j;k++)
        {
            dp[i][j]=min(dp[i][j],(solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]));
        }
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i=1,j=N-1;
        memset(dp,-1,sizeof dp);
        return solve(arr,i,j);
    }
int main()
{
    int n;
    cin>>n;
    int a[n];
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(a,1,n-1);
}




