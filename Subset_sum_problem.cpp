#include<bits/stdc++.h>
using namespace std;
bool is_Subset_sum(int Sum,int arr[],int n)
{
    bool t[n+1][Sum+1];
    for (int i = 0; i <=n; i++)
    {
        t[i][0]=1;
    }
    for (int j = 0; j <=Sum; j++)
    {
        t[0][j]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=Sum;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][Sum];
}
int main()
{
    cout<<"Enter the no. of elements";
    int n;
    cin>>n;
    cout<<"Enter the elements";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Sum";
    int Sum;
    cin>>Sum;
    cout<<is_Subset_sum(Sum,arr,n);
}