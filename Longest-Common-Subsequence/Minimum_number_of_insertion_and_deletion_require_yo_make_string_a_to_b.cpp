#include<iostream>
using namespace std;
int minOperations(string str1, string str2) 
	{ 
	    int x=str1.length();
	    int y=str2.length();
	    int dp[x+1][y+1];
	    for(int i=0;i<=x;i++)
	    {
	        for(int j=0;j<=y;j++)
	        {
	            if(i==0||j==0)
	            {
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<=x;i++)
	    {
	        for(int j=1;j<=y;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	            {
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else
	            {
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
        cout<<"deletions"<<x-dp[x][y]<<" "<<"insertions"<<y-dp[x][y]<<endl;
	    return (x-dp[x][y])+(y-dp[x][y]);
	}
int main()
{
    string text1;
    string text2;
    cout<<"Wnter first string";
    cin>>text1;
    cout<<"Enter second string";
    cin>>text2;
    minOperations(text1,text2);
}