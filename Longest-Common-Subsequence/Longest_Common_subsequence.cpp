#include<bits/stdc++.h>
using namespace std;
int LCS(string text1,string text2)
{
        int x=text1.length();
        int y=text2.length();
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=y;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];    
}
int main()
{
    string text1;
    string text2;
    cout<<"Enter first string";
    cin>>text1;
    cout<<"Enter second string";
    cin>>text2;
    cout<<LCS(text1,text2);
}



// recursive
// x=text1.length();
// y=text2.length();
// int lcs(string text1,string text2,x,y)
// {
//     if(x==0||y==0)
//     {
//         return 0;
//     }
//     else if(text1[x]==text2[y])
//     {
//         return 1+lcs(text1,text2,x-1,y-1);
//     }
//     else
//     {
//         return max(lcs(text1,text2,x-1,y),lcs(text1,text2,x,y-1))
//     }
// }