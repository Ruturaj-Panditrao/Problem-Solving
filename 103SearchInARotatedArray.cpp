/*
Problem Link :
https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   
    int pivotIndex(int A[],int l,int h){
        while(l<h){
            int mid=(l+h)/2;
            if(A[mid]>=A[0]){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        return l;
    }
    int binarySearch(int arr[],int low,int high,int k){
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==k)
        {
            return mid;
        }
        if(arr[mid]<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int pivot=pivotIndex(A,l,h);
        if(key>=A[pivot] && key<=A[h]){
            return binarySearch(A,pivot,h,key);
        }
        else{
            return binarySearch(A,0,pivot-1,key);
        }
    }




};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
