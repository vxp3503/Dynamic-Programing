#include<bits/stdc++.h>
using namespace std;
string SCS(string text1,string text2)
{
    int n=text1.length();
    int m=text2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n,j=m;
    string answer="";
    while(i>0&&j>0)
    {
        if(text1[i-1]==text2[j-1])
        {
            answer+=text1[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                answer+=text1[i-1];
                i--;
            }
            else
            {
                answer+=text2[j-1];
                j--;
            }
        }
    }

    while(i>0)
    {
        answer+=text1[i-1];
        i--;
    }
    while (j>0)
    {
        answer+=text2[j-1];
        j--;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
int main()
{
    string text1,text2;
    cout<<"Enter string1";
    cin>>text1;
    cout<<"Enter string2";
    cin>>text2;
    cout<<SCS(text1,text2);
}