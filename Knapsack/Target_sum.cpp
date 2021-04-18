#include<bits/stdc++.h>
using namespace std;
int Count_the_subset_with_given_sum(int n,int arr[],int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]==0)
            {
                dp[i][j]=0;
            }
            else if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}
int Target_sum(int arr[],int n,int differ)
{
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(arr[i-1]==0)
        {
            cnt++;
        }
    }
    if((sum+differ)%2!=0)
    {
        return 0;
    }
    if(differ>sum)
    {
        return 0;
    }
    int sum1=(sum+differ)/2;
    return pow(2,cnt)*Count_the_subset_with_given_sum(n,arr,sum1);
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
    int sum;
    cout<<"Enter Sum";
    cin>>sum;
    cout<<Target_sum(arr,n,sum);
}



// // This problem is just a variation of Count the number of Subsets with a given difference
// // Points to be considered:-
// // Sum(S1) - Sum(S2) = diff --------------> 1
// // Sum(S1) + Sum(S2) = Sum(arr) ----------> 2

// // Adding 1 & 2

// // Sum(S1) = ( diff + Sum(arr) ) / 2

// // Now the problem got reduced to count the number of subsets with given sum i.e. Sum(S1)
// // Just a variation of 0/1 Knapsack

// // Important Note for initialisation Part:-

// /* 
// Here zeros are involved in the array, therefore INITIALISATION part of the code changes a bit. For Example:
// When the given input is arr=[0,0,0,0,1] the 0th column in the t[n+1][Sum+1] matrix will no longer be filled with 1's. The reason is that whenever a particular element in the array arr[i] is encountered to be 0, the number of subsets in that array(till length i) which would give sum =0 would no longer be 1, now in addition to the empty subset we also have a subset {0} which would give subset sum=0. 
// */

// class Solution {
// public:
    
//     // Count Subsets with given sum
//     int CountSubsets(vector<int> &arr,int Sum,int n)
//     {
//        int t[n+1][Sum+1]; // 2D array for storing subproblems result

//        // Base Case initialization
//        for(int j=0;j<Sum+1;++j)
//         t[0][j] = 0; // subset sum is not possible for empty array

//        // for(int i=0;i<n+1;++i)
//        //  t[i][0] = 1; // Zero sum possible for empty subset
       
//        t[0][0] = 1; // Zero sum possible for empty subset
        
//        for(int i=1;i<n+1;++i)
//         if(arr[i-1]==0)
//         {
//             // For sum 0, Empty subset + subset made by 0 element
//             // By multiplying pow(2,cnt), it will consider all the subsets of 0 which was               
// 			// not considered earlier.
//             t[i][0]=2*t[i-1][0]; 
//         }
                
//         else
//         {
//              t[i][0]=t[i-1][0];
//         }

//        for(int i=1;i<n+1;++i)
//         for(int j=1;j<Sum+1;++j)
//         {
//             if(arr[i-1] <= j)
//                 t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
//             else if(arr[i-1] > j)
//                 t[i][j] = t[i-1][j];
//         }

//        return t[n][Sum];
//     } 
    
//     int findTargetSumWays(vector<int>& nums, int S) {
        
//         int SumOfNums = 0;
        
//         for(int i=0;i<nums.size();++i)
//             SumOfNums = SumOfNums + nums[i];
        
//         // Here S is actually difference
        
//         // We would never get the difference S by partitioning the array into two subsets. 
//         if(SumOfNums < S || (SumOfNums + S)%2 != 0 ) 
//             return 0;
        
//         int SumOfS1 = (SumOfNums + S) / 2; //Derived from formula described at start of code
        
//         int n = nums.size();
        
//         return CountSubsets(nums,SumOfS1,n); 
//     }
// };