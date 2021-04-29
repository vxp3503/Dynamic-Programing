#include <bits/stdc++.h>
using namespace std;
int LCString(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
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
            if (s1[i - 1] == s2[j - 1])
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
    string text2;
    cout << "Enter first string";
    cin >> text1;
    cout << "Enter second string";
    cin >> text2;
    cout << LCString(text1, text2);
}







// recursive
// x=text1.length();
// y=text2.length();
// int lcs(string text1,string text2,x,y,count)
// {
//     if(x==0||y==0)
//     {
//         return count;
//     }
//     if(text1[x]==text2[y])
//     {
//         count =lcs(text1,text2,x-1,y-1,count+1);
//     }
//     count= max(count,max(lcs(text1,text2,x-1,y,0),lcs(text1,text2,x,y-1,0)))
//     return count;
// }