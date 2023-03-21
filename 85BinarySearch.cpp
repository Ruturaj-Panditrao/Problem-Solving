/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/binary-search_972?leftPanelTab=0
*/

int binarySearch(int *input, int n, int val)
{
    long long int start = 0;
    long long int end = n-1;

    long long int mid = start + (end-start)/2;
    long long int answer = -1;
    while(start<=end)
    {
        if(input[mid]==val) 
        {
            answer = mid;
            break;
        }
        else if(input[mid]>val)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    mid = start + (end-start)/2;
    }
    return answer;
}
