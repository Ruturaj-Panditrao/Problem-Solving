/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/rotated-sorted-array-search_893009?leftPanelTab=0
*/

#include <bits/stdc++.h> 

int binarySearch(vector<int>arr, int start, int end, int x)
{
    int ans = -1;
    int mid = start + (end-start)/2;

    while(start <= end)
    {
        if(arr[mid]==x)
        {
            ans = mid;
            break;
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
int getIndexInRotatedArray(vector<int> &arr, int x)
{
   int index = 0;
   int start = 0;
   int n = arr.size();
   int end = n-1;
   int mid = start + (end-start)/2;
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


   if(arr[index]==x) return index;
   int i1 = binarySearch(arr,0,index,x);
   int i2 = binarySearch(arr,index,n-1,x);

   if(i1 >= 0 && i2< 0) return i1;
   else if(i2 >= 0 && i1<0) return i2;
   else return -1;
}
