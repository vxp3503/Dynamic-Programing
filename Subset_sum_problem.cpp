#include<bits/stdc++.h>
using namespace std;
bool is_Subset_sum(int Sum,int arr[],int n)
{
    bool t[n+1][Sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=Sum;j++)
        {
            if(i==0)
            {
                t[i][j]=0;
            }
            if(j==0)
            {
                t[i][j]=1;
            }
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i][j-arr[i-1]]||t[i-1][j];
            }
            else
            t[i][j]=t[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <=Sum; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
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