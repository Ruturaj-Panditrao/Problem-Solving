/*
Problem Link :
https://practice.geeksforgeeks.org/problems/minimum-number-in-a-sorted-rotated-array-1587115620/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
       
       if(arr[low]<arr[high])
       {
           return arr[low];
       }
       int n = low + high + 1;
       int start = low;
       int end = high;
       if(n==1) return arr[0];
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends
