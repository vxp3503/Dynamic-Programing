#include<bits/stdc++.h>
using namespace std;
int static dp[1001][1001];
bool is_palindrome(string text,int i,int j)
{
    if(i>j)
    {
        return 1;
    }
    if(i==j)
    {                                           //did not optimized
        return 1;
    }
    while (i<j)
    {
        if(text[i]!=text[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int Palindrome_Partioning(string text,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(is_palindrome(text,i,j))
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int left;
        int right;
        if(dp[i][k]!=-1)
        {
            left=dp[i][k];
        }
        else
        left=Palindrome_Partioning(text,i,k);

        if(dp[k+1][j]!=-1)
        {
            right=dp[k+1][j];
        }
        else
        right=Palindrome_Partioning(text,k+1,j);
        int temp=1+left+right;
        mini=min(temp,mini);
    }
    return dp[i][j]=mini;
}
int main()
{
    string text;
    cin>>text;
    memset(dp,-1,sizeof dp);
    int i=0,j=text.length()-1;
    cout<<Palindrome_Partioning(text,i,j);         
}