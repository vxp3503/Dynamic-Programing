#include<bits/stdc++.h>
using namespace std;
int LPS(string text1)
{
    string text2 = text1;
    reverse(text1.begin(), text1.end());
    int x = text1.length();
    int y = text2.length();
    int dp[x + 1][y + 1];
    for (int i = 0; i <= x; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= y; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[x][y];
}
int deletion(string text1)
{
    return text1.length()-LPS(text1);
}
int main()
{
    string text1;
    cout<<"Enter First String";
    cin>>text1;
    cout<<deletion(text1);
}