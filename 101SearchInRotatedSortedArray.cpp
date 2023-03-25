/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_630450?leftPanelTab=0
*/

int binarySearch(int * arr, int start, int end, int key)
{
    int ans = -1;
    int mid = start + (end-start)/2;
    while(start <= end)
    {
        if(arr[mid]==key)
        {
            ans = mid;
            break;
        }
        else if(key > arr[mid])
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

int search(int* arr, int n, int key)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end-start)/2;

    int index = 0;

    while(start <= end)
    {
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;

        if(arr[mid]<arr[prev] && arr[mid]<arr[next])
        {
            index = mid;
            break;
        }
        else if(arr[mid] > arr[end])
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }

        mid = start + (end-start)/2;
    }

    if(arr[index]==key) return index;
    
    int i1 = binarySearch(arr,0,index-1,key);
    int i2 = binarySearch(arr,index,n-1,key);

    if(i1 < 0 && i2 > 0)return i2;
    else if(i2 < 0 && i1 > 0) return i1;
    else return -1; 
}
