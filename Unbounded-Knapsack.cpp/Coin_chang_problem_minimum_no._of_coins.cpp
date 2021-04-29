#include <bits/stdc++.h>
using namespace std;
int coin_change_problem_minimum_number_of_coins(int coins[], int n, int amount)
{
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[1][i] = i / coins[0];
        }
        else
        {
            dp[1][i] = INT_MAX - 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][amount] == INT_MAX - 1)
    {
        return -1;
    }
    return dp[n][amount];
}
int main()
{
    int n;
    cout << "Enter the no. of coins";
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the amount";
    int amount;
    cin >> amount;
    cout << coin_change_problem_minimum_number_of_coins(coins, n, amount);
}