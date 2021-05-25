#include<bits/stdc++.h>
using namespace std;

int LPstring(string text1)
{
    string text2=text1;
    reverse(text1.begin(),text1.end());
    int n = text1.length();
    int m = text2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (max <= dp[i][j])
            {
                max = dp[i][j];
            }
        }
    }
    return max;
}
int main()
{
    string text1;
    cin>>text1;
    cout<<LPstring(text1);
}