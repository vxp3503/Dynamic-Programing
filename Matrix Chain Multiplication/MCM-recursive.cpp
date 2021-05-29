#include<bits/stdc++.h>
using namespace std;
int Solve(int arr[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    int min=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int cost=Solve(arr,i,k)+Solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(cost<=min)
        {
            min=cost;
        }
    }
    return min;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<Solve(a,1,n-1);
}