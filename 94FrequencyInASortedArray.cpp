/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/frequency-in-a-sorted-array_893286?leftPanelTab=0
*/

int fOcc(vector<int>arr, int x)
{
    int start = 0;
    int end = arr.size()-1;
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

int lOcc(vector<int>arr, int x)
{
    int start = 0;
    int end = arr.size()-1;
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
int countOccurrences(vector < int > arr, int x)
{
    int f = fOcc(arr,x);
    int l = lOcc(arr,x);

    if(f==-1 && l==-1) return 0;
    else return l-f+1;
}
