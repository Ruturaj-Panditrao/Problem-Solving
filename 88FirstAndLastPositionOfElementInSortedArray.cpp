/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_839724?leftPanelTab=0
*/

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	int firstOcc = -1;
	int lastOcc = -1;

	int start = 0;
	int end = n-1;

	int mid = start + (end - start)/2;

	while(start <= end)
	{
		if(arr[mid]==x)
		{
			firstOcc = mid;
			end = mid-1;
		}
		else if(arr[mid]>x)
		{
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}

		mid = start + (end-start)/2;
	}

	int start2 = 0;
	int end2 = n-1;

	int mid2 = start + (end-start)/2;

	while(start2<=end2)
	{
		if(arr[mid2]==x)
		{
			lastOcc = mid2;
			start2 = mid2+1;
        }
		else if (x > arr[mid2]) 
		{
            start2 = mid2 + 1;
        } else
		{
			end2 = mid2-1;
        }

		mid2 = start2 + (end2-start2)/2;
    }

	return {firstOcc,lastOcc};
}

