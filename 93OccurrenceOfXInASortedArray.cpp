/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/occurrence-of-x-in-a-sorted-array_630456?leftPanelTab=0
*/

int fOcc(int arr[], int n, int target)
{	
	int ans = -1;
	int start = 0;
	int end = n-1;

	int mid = start + (end-start)/2;

	while(start <= end)
	{
		if(arr[mid]==target)
		{
			ans = mid;
			end = mid-1;
		}
		else if(arr[mid]>target)
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
		mid = start + (end-start)/2;
	}

	return ans;
}

int lOcc(int arr[], int n, int target)
{
	int start = 0;
	int end = n-1;
	int ans = -1;
	int mid = start + (end-start)/2;

	while(start<=end)
	{
		if(arr[mid]==target)
		{
			ans = mid;
			start = mid+1;
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
int countOccurences(int arr[], int n, int X)
{
	int firstOcc = fOcc(arr,n,X);
	int lastOcc = lOcc(arr,n,X);

	if(firstOcc == -1 && lastOcc == -1) return 0;
	else return (lastOcc - firstOcc +1);
}
