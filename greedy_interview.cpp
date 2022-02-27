/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int>v1,vector<int>v2)
{
   return v1[2]>v2[2];
}
vector<int>job_sequence_problem(vector<vector<int>>&vc,int row)
{
    int deadline=-1;
    sort(vc.begin(),vc.end(),comp);
    for(int i=0;i<row;i++)
    {
        deadline=max(deadline,vc[i][1]);
    }
    int arr[deadline+1];
    for(int i=1;i<=deadline;i++)
    {
        arr[i]=-1;
    }
    arr[0]=0;
    int job=0;
    int profit=0;
    for(int i=0;i<row;i++)
    {
        if(arr[vc[i][1]]==-1)
        {
            arr[vc[i][1]]=vc[i][0];
            profit+=vc[i][2];
            job++;
        }
        else
        {
            int left_deadlines=vc[i][1]-1;
            while(left_deadlines>=1)
            {
                if(arr[left_deadlines]==-1)
                {
                    arr[vc[i][1]]=vc[i][0];
                    profit+=vc[i][2];
                    job++;
                    break;
                }
                left_deadlines--;
            }
        }
    }
    vector<int>total;
    total.push_back(job);
    total.push_back(profit);
    return total;
}
bool comp2(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second==p2.second)
    {
       return true;
    }
    return p1.second<p2.second;
}
int maximum_meeting(int *arr1,int*arr2,int n)
{
    vector<pair<int,int>>vc;
    for(int i=0;i<n;i++)
    {
        vc.push_back(make_pair(arr1[i],arr2[i]));  
    }
    sort(vc.begin(),vc.end(),comp2);
    for(int i=0;i<vc.size();i++)
    {
        cout<<vc[i].first<<" "<<vc[i].second<<endl;
    }
    int count=1;
    int limit=vc[0].second;
    for(int i=1;i<vc.size();i++)
    {
        if(vc[i].first>limit)
        {
            limit=vc[i].second;
            count++;
        }
    }
    return count;
}
int minimum_platform_needed(int *arr1,int*arr2,int n)
{
    sort(arr1,arr1+n);
    sort(arr2,arr2+n);
    int platform=1;
    int maxi=platform;
    int i=1;
    int j=0;
    while(i<n and j<n)
    {
        if(arr1[i]<=arr2[j])
        {
            platform++;
            i++;
        }
        else{
            platform--;
            j++;
            
        }
        maxi=max(maxi,platform);
        
    }
    return maxi;
}
bool comp4(pair<int,int>p1,pair<int,int>p2)
{
    return ((double)p1.second/(double)p1.first)>((double)p2.second/(double)p2.first);
}
double fractional_knapsack(int *weight,int *value,int n,int capacity)
{
    vector<pair<int,int>>vc;
    for(int i=0;i<n;i++)
    {
        vc.push_back(make_pair(weight[i],value[i]));
    }
    sort(vc.begin(),vc.end(),comp4);
    double profit=0.0;
    for(int i=0;i<vc.size();i++)
    {
        if(vc[i].first<=capacity)
        {
            profit+=vc[i].second;
            capacity-=vc[i].first;
        }
        else
        {
            profit+=(double)(vc[i].second*capacity)/(double)vc[i].first;
            break;
        }
    }
    return profit;
}
int minimum_coin_change(int n)
{
    int arr[9]={1,2,5,10,20,50,100,500,1000};
    int i=8;
    int count=0;
    while(i>=0)
    {
        if(arr[i]>n)
        {
            i--;
        }
        else
        {
            n=n-arr[i];
            count++;
            if(n==0)
            {
                break;
            }
        }
    }
    return count;
    
}
int main()
{
    int row;
    cin>>row;
    vector<vector<int>>vc(row,vector<int>(3));
    for(int i=0;i<row;i++)
    {
        vector<int>v;
        for(int j=0;j<3;j++)
        {
            int num;
            cin>>num;
            v.push_back(num);
        }
        vc.push_back(v);
    }
    vector<int>finals=job_sequence_problem(vc,row);
    for(auto z:finals)
    {
        cout<<z<<" ";
    }
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
     for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    cout<<maximum_meeting(arr1,arr2,n);
    cout<<minimum_platform_needed(arr1,arr2,n);
    int capacity;
    cin>>capacity;
    cout<<fractional_knapsack(arr1,arr2,n,capacity);
    cout<<minimum_coin_change(121);
    return 0;
}