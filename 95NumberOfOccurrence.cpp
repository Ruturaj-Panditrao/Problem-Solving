/*
Problem Link :
https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
	int focc(int arr[], int n, int x)
	{
	    int start = 0;
	    int end = n-1;
	    
	    int mid = start + (end-start)/2;
	    
	    int ans = -1;
	    
	    while(start <= end)
	    {
	        if(arr[mid]==x)
	        {
	            ans = mid;
	            end = mid-1;
	        }
	        else if(x > arr[mid])
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
	
	int locc(int arr[], int n, int x)
	{
	    int start = 0;
	    int end = n-1;
	    int mid = start + (end-start)/2;
	    
	    int ans = -1;
	    
	    while(start <= end)
	    {
	        if(arr[mid]==x)
	        {
	            ans = mid;
	            start = mid+1;
	        }
	        else if(x > arr[mid])
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
	int count(int arr[], int n, int x) 
	{
	    int f = focc(arr,n,x);
	    int l = locc(arr,n,x);
	    
	    if(f==-1 && l==-1) return 0;
	    else return l-f+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
