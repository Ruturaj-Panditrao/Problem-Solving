/*
Problem Link :
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

class Solution {
public:

    int binarySearch(vector<int>&arr, int start, int end, int target)
    {
        int ans = -1;
        int mid = start + (end-start)/2;

        while(start <= end)
        {
          if(arr[mid]==target)
          {
            ans = mid;
            break;
          }
          else if(target > arr[mid])
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
    int search(vector<int>& arr, int target) 
    {
        int index = 0;
       
       int start = 0;
       int end = arr.size()-1;
       int mid = start + (end-start)/2;
       int n = arr.size();
        while(start <= end)
        {
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;

            if(arr[mid]<arr[prev] && arr[mid]<arr[next])
            {
                index = mid;
                break;
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
       if(arr[index]==target) return index;
       int index1 = binarySearch(arr,0,index-1,target);
       int index2 = binarySearch(arr,index,n-1,target);
        cout<<index<<" ";
         cout<<index1<<" ";
          cout<<index2<<" ";
       if(index1 >= 0) return index1;

       if(index2 >= 0) return index2;
       else return -1;
    }
};
