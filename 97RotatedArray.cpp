/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?leftPanelTab=0
*/

int rotatedArray(vector<int> arr, int n)
{
   int start = 0;
   int end = n-1;
   int mid = start + (end-start)/2;

    if(n==1)
    {
        return arr[0];
    }
   while(start<=end)
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

   return -1;
}
