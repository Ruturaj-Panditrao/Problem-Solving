/*
Problem Link :
https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n)
    {
        if(n==1) return arr[0];
        
        int start = 0;
        int end = n-1;
        int mid = start + (end-start)/2;
        
        while(start <= end)
        {
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(arr[mid]<arr[prev] && arr[mid]<arr[next])
            {
                return arr[mid];
            }
            else if(arr[mid]>arr[end])
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
