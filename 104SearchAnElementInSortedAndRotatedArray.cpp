/*
Problem Link :
https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array0959/1
*/

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 

int binarySearch(vector<int>vec, int start, int end, int K)
{
    int mid = start + (end-start)/2;
    int ans = -1;
    
    while(start <= end)
    {
        if(vec[mid]==K)
        {
            ans = mid;
            break;
        }
        else if(K > vec[mid])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        
        mid = start + (end-start)/2;
    }
    
    return ans;
}
int Search(vector<int> vec, int K)
{
    int index = 0;
    int start = 0;
    int n = vec.size();
    int end = n-1;
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        
        if(vec[mid]<vec[prev] && vec[mid]<vec[next])
        {
            index = mid;
            break;
        }
        else if(vec[mid]> vec[end])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
        
        mid = start + (end-start)/2;
    }
    
    if(vec[index]==K) return index;
    int i1 = binarySearch(vec,0,index-1,K);
    int i2 = binarySearch(vec,index,n-1,K);
    
    if(i1>=0 && i2<0) return i1;
    else if(i2>=0 && i1<0) return i2;
    else return -1;
}
