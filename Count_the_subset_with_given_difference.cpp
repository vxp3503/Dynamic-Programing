#include<iostream>
using namespace std;
int Count_the_subset_with_given_sum(int arr[],int Sum,int n)
{
    int dp[n+1][Sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=Sum;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=Sum;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][Sum];
}
int count_the_subset_with_given_difference(int arr[],int n,int differ)
{
    int Sum=0;
    for(int i=0;i<n;i++)
    {
        Sum=Sum+arr[i];
    }
    int Sum1;
    Sum1=(differ+Sum)/2;
    return Count_the_subset_with_given_sum(arr,n,Sum1);
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
    cout<<"Enter Difference";
    int Differ;
    cin>>Differ;
    cout<<count_the_subset_with_given_difference(arr,n,Differ);
}