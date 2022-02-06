#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int unbounded_knapsack(int n,int*weight,int *value,int capacity)
{
    int dp[n+1][capacity+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<capacity+1;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(weight[i-1]<=j)
            {
                dp[i][j]=max(value[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}
//rod cutting problem
int rod_cutting(int n,int*profit,int length)
{
    int dp[n+1][length+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<length+1;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(i<=j)
            {
                dp[i][j]=max(profit[i-1]+dp[i][j-i],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][length];
}
//total number of ways to make the coin 
int total_ways_coin(int n,int*coins,int value)
{
    int dp[n+1][value+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<value+1;j++)
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
            else if(coins[i-1]<=j)
            {
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][value];
}
int minimum_coins_needed(int n,int coin, int *changes)
{
    int dp[n+1][coin+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=coin;j++)
        {
            if(i==0)
            {
                dp[i][j]=INT_MAX-1;
            }
            else if(i==1)
            {
                if((j%changes[i-1])==0)
                {
                    dp[i][j]=j/changes[i-1];
                }else
                {
                    dp[i][j]=INT_MAX-1;
                }
            }
            else if(j==0)
            {
                dp[i][j]=0;
            }
            else if(changes[i-1]<=j)
            {
                dp[i][j]=min(1+dp[i][j-changes[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][coin];
}
int longest_common_subsequence(int n1,int n2,string s1,string s2)
{
    if(n1==0 or n2==0)
    {
        return 0;
    }
    else if(s1[n1-1]==s2[n2-1])
    {
        return 1+longest_common_subsequence(n1-1,n2-1,s1,s2);
    }
    else
    {
        return max(longest_common_subsequence(n1,n2-1,s1,s2),longest_common_subsequence(n1-1,n2,s1,s2));
    }
}
int longest_common_subsequence_dp(int n1,int n2,string s1,string s2)
{
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n1][n2];
    
}
string print_longest_common_subsequence(int n1,int n2,string s1,string s2)
{
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    string finals="";
    int i=n1;
    int j=n2;
    while(i>0 and j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            finals=s1[i-1]+finals;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>=dp[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    return finals;
}
//longest common substring
int longest_common_substring_dp(int n1,int n2,string s1,string s2)
{
    int maxi=INT_MIN;
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                maxi=max(maxi,dp[i][j]);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    return maxi;
    
}
int shortest_common_supersequence(int n1,int n2,string s1,string s2)
{
     int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return n1+n2-dp[n1][n2];
}
void minimum_insertion_deletion_convert_a_to_b(int n1,int n2,string a,string b)
{
     int dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<"deletion"<<" "<<n1-dp[n1][n2]<<endl;
    cout<<"insertion"<<" "<<n2-dp[n1][n2]<<endl;
}
int longest_palindromic_subsequence(int n1,string s1)
{
    int dp[n1+1][n1+1];
    string s2=s1;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n1;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n1][n1];
    
}
int minimum_deletion_make_string_palindrome(int n1,string s1)
{
    string s2=s1;
    reverse(s2.begin(),s2.end());
     int dp[n1+1][n1+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n1;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return n1-dp[n1][n1];
}
int longest_repeating_subsequence(int n1,string s1)
{
    string s2=s1;
     int dp[n1+1][n1+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n1;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1] and i!=j)
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n1][n1];
}


int main()
{
// KNAPSACK PROBLEM VARIATIONS//
        int n;
        cin>>n;
        int weight[n];
        int value[n];
        for(int i=0;i<n;i++)
        {
            cin>>weight[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>value[i];
        }
        int capacity;
        cin>>capacity;
        cout<<unbounded_knapsack(n,weight,value,capacity);
        int length;
        cin>>length;
        cout<<rod_cutting(n,value,length);
        cout<<total_ways_coin(n,weight,length);
        int coin;
        cin>>coin;
        cout<< minimum_coins_needed(n,coin,weight);
//-------------------------------------------------------------------------//

    //LONGEST COMMON SUBSEQUENCE VARIATIONS//
    
        string s1,s2;
        cin>>s1>>s2;
        int n1=s1.length();
        int n2=s2.length();
        cout<<longest_common_subsequence(n1,n2,s1,s2);
        cout<<longest_common_subsequence_dp(n1,n2,s1,s2);
        cout<<print_longest_common_subsequence(n1,n2,s1,s2);
        cout<<longest_common_substring_dp(n1,n2,s1,s2);
        cout<<shortest_common_supersequence(n1,n2,s1,s2);
        minimum_insertion_deletion_convert_a_to_b(n1,n2,s1,s2);
        cout<<longest_palindromic_subsequence(n1,s1);
        cout<<minimum_deletion_make_string_palindrome(n1,s1);
        cout<<longest_repeating_subsequence(n1,s1);

    return 0;
}
