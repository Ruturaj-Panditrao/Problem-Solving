/*
Problem Link :
https://leetcode.com/problems/first-bad-version/description/?envType=study-plan&id=algorithm-i
*/


class Solution
{
public:
    int firstBadVersion(int n)
    {
        int start = 1;
        int end = n;
        int answer = -1;

        int mid = start + (end-start)/2;

        while(start<=end)
        {
            if(isBadVersion(mid))
            {
                answer = mid;
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
};
