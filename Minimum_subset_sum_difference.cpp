#include<bits/stdc++.h>
using namespace std;
vector<int> Subset_sum(int arr[],int Sum,int n)
{
    vector<int>sum;
    bool dp[n+1][Sum+1];
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
        for (int j = 1; j <= Sum; j++)
        {
            if(j>=arr[i-1])
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=Sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=Sum/2;i++)
    {
        if(dp[n][i]==1)
        {
            sum.push_back(i);
        }
    }
    return sum;
}
int minimum_subset_sum_difference(int arr[],int n)
{
    int range=0;
    for(int i=0;i<n;i++)
    {
        range=arr[i]+range;
    }
    vector<int>sum=Subset_sum(arr,range,n);
    int min=INT_MAX;
    for(int i=0;i<sum.size();i++)
    {
        if((range-2*sum[i])<min)
        {
            min=(range-2*sum[i]);
        }
    }
    return min;
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
    cout<<minimum_subset_sum_difference(arr,n);
}