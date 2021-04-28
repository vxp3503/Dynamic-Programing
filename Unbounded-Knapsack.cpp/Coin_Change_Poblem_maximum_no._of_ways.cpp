#include<bits/stdc++.h>
using namespace std;
int coin_change_problem_maximum_number_of_ways(int coins[],int n,int amount)
{
        int dp[n+1][amount+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
       for(int i=1;i<=amount;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount];
}
int main()
{
    int n;
    cout<<"Enter the no. of coins";
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<"Enter the amount";
    int amount;
    cin>>amount;
    cout<<coin_change_problem_maximum_number_of_ways(coins,n,amount);
}