/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;

// maximum_subarray_sum having a window of k size
int maximum_subarray_k(int n,int *arr,int k)
{
    int j=0;
    int sum=0;
    int maxi=-1;
    int i=0;
    while(i<n)
    {
        sum+=arr[i];
        if(i-j+1<k)
        {
            i++;
        }
        else
        {
            maxi=max(maxi,sum);
            sum=sum-arr[j];
            i++;
            j++;
        }
    }
    return maxi;
}
// first negative number in each window of size k
vector<int>first_negative_number_k(int n, int *arr,int k)
{
    vector<int>v;
    queue<int>q;
    int j=0;
    int i=0;
    while(i<n)
    {
        if(arr[i]<0)
        {
            q.push(arr[i]);
        }
        if(i-j+1<k)
        {
            i++;
        }
        else
        {
            if(q.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(q.front());
                if(q.front()==arr[j]);
                {
                    q.pop();
                }
            }
            i++;
            j++;
        }
    }
    return v;
}
// count  total anagrams in a string having a complexity of n*(nlogn)
int count_anagrams(string s,string ana)
{
    int len=ana.size();
    int i=0;
    int j=0;
    sort(ana.begin(),ana.end());
    int count=0;
    while(i<s.length())
    {
        if((i-j+1)<len)
        {
            i++;
        }
        else if((i-j+1)==len)
        {
            string sub=s.substr(j,(i-j+1));
            
            sort(sub.begin(),sub.end());
            if(ana==sub)
            {
                count++;
                
                
            }
           i++;
           j++;
        }
    }
    return count;

}
// count anagrams in a string having a complexity of order n
int count_anagrams_better(string s,string pattern)
{
    map<char,int>mp;
    for(int i=0;i<pattern.length();i++)
    {
        mp[pattern[i]]++;
    }
    int count=mp.size();
    int i,j;
    i=0,j=0;
    int n=s.length();
    int k=pattern.length();
    int ans=0;
    while(i<n)
    {
        if(mp.find(s[i])!=mp.end())
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                count=count-1;
            }
        }
        if(i-j+1<k)
        {
            i++;
        }
        else if(i-j+1==k)
        {
            if(count==0)
            {
                ans=ans+1;
            }
            
            if(mp.find(s[j])!=mp.end())
                {
                    mp[s[j]]++;
                    if(mp[s[j]]==1)
                    {
                        count+=1;
                    }
                }
               
            i++;
            j++;
        }
        
    }
   return ans;
}
// find the maximum from an array of each window of size k
void maximum_from_all_subarray_k(int *arr, int k,int n)
{
    int i=0,j=0;
    int maxi=INT_MIN;
    while(i<n)
    {
        maxi=max(maxi,arr[i]);
        if(i-j+1<k)
        {
            i++;
        }
        else if(i-j+1==k)
        {
            cout<<maxi<<" ";
            if(arr[j]==maxi)
            {
                maxi=INT_MIN;
            }
            i++;
            j++;
        }
    }
}
// longest subarray of a given target
int largest_subarray_sum_target(int *arr,int n,int target)
{
    int i=0,j=0;
    int sum=0;
    int maxi=-1;
    while(i<n)
    {
        sum+=arr[i];
        if(sum==target)
        {
            maxi=max(maxi,i-j+1);
        }
        if(sum<target)
        {
            i++;
        }
        else
        {
            sum=sum-arr[j];
            i++;
            j++;
        }
    }
    return maxi;
}
// longest substring with k unique characters
int longest_substring_with_kunique(string s,int k)
{
    int n=s.length();
    int maxi=-1;
    map<char,int>mp;
    int i=0,j=-1;
    while(i<n)
    {
        mp[s[i]]++;
        if(mp.size()==k)
        {
            maxi=max(maxi,i-j+1);
            i++;
           
        }
        if(mp.size()<k)
        {
            i++;
        }
        else if(mp.size()>k)
        {
            while(j<=i)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    mp.erase(s[j]);
                    if(mp.size()==k)
                    {
                        maxi=max(maxi,i-j);
                        j++;
                        break;
                        
                    }
                }
                j++;
            }
            i++;
        }
    }
    return maxi;
}
// longest substring without repeating characters
int longest_without_repeating_characters(string s)
{
    int n=s.length();
    int i=0,j=0;
    map<char,int>mp;
    int maxi=-1;
    while(i<n)
    {
        mp[s[i]]++;
        if(mp[s[i]]<=1)
        {
            
            maxi=max(maxi,i-j+1);
            i++;
        }
        else
        {
            while(j<i)
            {
                
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    mp.erase(s[j]);
                }
                else if(mp[s[j]]==1)
                {
                   
                   j++;
                    break;
                }
                j++;
              
            }
            i++;
        }
    }
    return maxi;
}
// minimum window substring,print the substring of minimum length of another given string
void minimum_window_substring(string s,string t)
{
    map<char,int>mp;
    for(int i=0;i<t.length();i++)
    {
        mp[t[i]]++;
    }
    map<char,int>mp2;
    int count=0;
    int i,j=0;
    int last,first;
    int mini=INT_MAX;
   for(i=0;i<s.length();i++)
    {
        mp2[s[i]]++;
        if(mp.find(s[i])!=mp.end())
        {
            if(mp2[s[i]]<=mp[s[i]])
            {
                count++;
            }
        }
        if(count==t.length())
        {
            char ch=s[j];
            while(mp.find(ch)==mp.end() or (mp.find(ch)!=mp.end() and mp2[ch]!=mp[ch]))
            {
                mp2[ch]--;
                j++;
                ch=s[j];
                
            }
            if((i-j+1)<mini)
                {
                    mini=i-j+1;
                    last=i+1;
                    first=j;
                }
        }
        
    }
    
    string finals="";
   for(int i=first;i<last;i++)
   {
       finals+=s[i];
   }
   cout<<finals;
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;cin>>k;
    cout<<maximum_subarray_k(n,arr,k);
    vector<int>vc=first_negative_number_k(n,arr,k);
    for(auto z:vc)
    {
        cout<<z<<" ";
    }
    string s;
    cin>>s;
    string s2;
    cin>>s2;
    string ana;
    cin>>ana;
    cout<<count_anagrams(s,ana);
    cout<<count_anagrams_better(s,ana);
    maximum_from_all_subarray_k(arr,k,n);
    cout<<largest_subarray_sum_target(arr,n,k);
    cout<<longest_substring_with_kunique( s, k);
    cout<<longest_without_repeating_characters(s);
    minimum_window_substring(s,s2);
    return 0;
}

