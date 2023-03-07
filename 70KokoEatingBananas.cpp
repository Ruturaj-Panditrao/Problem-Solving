/*
Problem Solving :
https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution
{
public:

    int isCorrectSpeed(int k, vector<int>&piles, int h)
    {
        long int counter = 0;
        for(int i=0; i<piles.size();i++)
        {
            if(piles[i]<=k)
            {
                counter+=1;
            }
            else
            {
                counter+=1;
                counter+=((piles[i]-1)/k);
            }
        }
        return counter;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {   
        int answer = 0;
        int minn = *min_element(piles.begin(),piles.end());
        int maxx = *max_element(piles.begin(),piles.end());

        if(h == piles.size())
        {
            // Piles's Max Value will exactly take size of Pile's Time
            answer = maxx;
        }
        else
        {
            long int start = 1;
            long int end = maxx;
            // Eating Speed > maxx 
            // Will do the same work as maxx
            // [3,6,7,11]
            // For example, eating speed = 11 -> 4 hours
            // If eating speed = 12,13,14,... -> 4 hours
            // Hence our answer need not be looked after 11
            // So we can apply binary search in the range [1 to 11]  

            long int mid = start + (end-start)/2;

            while(start<end)
            {
                if(isCorrectSpeed(mid,piles,h)<=h)
                {
                    end = mid;
                }
                else
                {
                    start = mid+1;
                }

                mid = start + (end-start)/2;
            }

            answer = start;
        }
            return answer;
    }
};
