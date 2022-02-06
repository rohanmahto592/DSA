
#include <stdio.h>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

//knapsack using recursion
int knapsack(int n,int *weight,int *value,int W)
{
    if(n==0 or W==0)
    {
        return 0;
    }
    if(weight[n]<=W)
    {
        return max((value[n]+ knapsack(n-1,weight,value,W-weight[n])),knapsack(n-1,weight,value,W));
    }
    else
    {
        return knapsack(n-1,weight,value,W);
    }
}
// knapsack using recursion+ memoization(Dp)
int tab[1001][1001];

int knapsack_memoized(int n,int *weight,int *value,int W)
{
    if(n==0 or W==0)
    {
        return 0;
    }
    if(tab[n][W]!=-1)
    {
        return tab[n][W];
    }
    else
    {
    if(weight[n]<=W)
    {
        return tab[n][W]=max((value[n]+ knapsack_memoized(n-1,weight,value,W-weight[n])),knapsack_memoized(n-1,weight,value,W));
    }
    else
    {
        return tab[n][W]=knapsack_memoized(n-1,weight,value,W);
    }
    }
}
// knapsack using tabulation
int knapsack_tabulation(int n, int W,int *weight,int*value)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
// subset sum problem using recursion
bool subset_problem(int n,int*arr, int sum)
{
    if(n==0 and sum==0)
    {
        return true;
    }
    else if(sum==0)
    {
        return true;
    }
    else if(n==0)
    {
        return false;
    }
    else if(arr[n]<=sum)
    {
        return subset_problem(n-1,arr,sum-arr[n])+subset_problem(n-1,arr,sum);
    }
    else
    {
        return subset_problem(n-1,arr,sum);
    }
}
// subset sum problem using tabulation
bool subset_problem_tab(int n, int*arr,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=true;
            }
            else if(i==0)
            {
                dp[i][j]=false;
            }
            else if(j==0)
            {
                dp[i][j]=true;
            }
            else if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
//count of total number of subset for a given sum
int count_subset_problem_tab(int n, int*arr,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                dp[i][j]=0;
            }
            else if(j==0)
            {
                dp[i][j]=1;
            }
            else if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
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
//find the minimum subset sum difference
int minimum_subset_sum_difference(int n,int sum,int *arr,int range)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j]=true;
            }
            else if(i==0)
            {
                dp[i][j]=false;
            }
            else if(j==0)
            {
                dp[i][j]=true;
            }
            else if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<=sum;i++)
    {
        if(dp[n][i]==true)
        {
            mini=min(mini,(range-2*i));
        }
    }
    return mini;
}

int main()
{
    int n,W;
    cin>>n>>W;
    int weight[n],value[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    cout<<knapsack(n-1,weight,value,W);
    memset(tab,-1,sizeof(tab));
    cout<<knapsack_memoized(n-1,weight,value,W);
    cout<<knapsack_tabulation(n,W,weight,value);
    cout<<subset_problem(n-1,weight,W);
    cout<<subset_problem_tab(n,weight,W);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=weight[i];
    }
    if(sum%2!=0)
    {
        cout<<"cannot be equal partition";
    }
    else
    {
        cout<<subset_problem_tab(n,weight,sum/2);
    }
    cout<<count_subset_problem_tab(n,weight,W);
    cout<<minimum_subset_sum_difference(n,sum/2,weight,sum);
    
  
    return 0;
}

