#include <bits/stdc++.h>
using namespace std;
int Length_of_SCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return (m + n) - dp[m][n];
}
int main()
{
    string text1;
    string text2;
    cout << "Enter first string";
    cin >> text1;
    cout << "Enter second string";
    cin >> text2;
    cout << Length_of_SCS(text1, text2);
}