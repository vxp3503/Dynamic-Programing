#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    vector<int>answer;
    int n=a.size();
    int m=b.size();
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
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else 
            {
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n;
    int j=m;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            answer.push_back(a[i-1]);
            i--;
            j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i=i-1;
            }
            else {
             j=j-1;
            }
        }
    }
    // answer.push_back(dp[n][m]);
    reverse(answer.begin(),answer.end());
    return answer;
}

int main() {
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int>a;
    vector<int>b;
    for(int i=0;i<n;i++)
    {
        int item;
        a.push_back(item);
    }
    for(int i=0;i<m;i++)
    {
        int item;
        b.push_back(item);
    }
    vector<int>answer=longestCommonSubsequence(a, b);
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
}
