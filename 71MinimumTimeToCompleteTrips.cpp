/*
Probllem Link :
https://leetcode.com/problems/minimum-time-to-complete-trips/description/
*/

class Solution 
{
public:

    long long int isValid(long long int t, vector<int>&time, int totalTrips)
    {
        long long int counter = 0;
        for(int i=0; i<time.size();i++)
        {
            counter += (t/time[i]);
        }

        return counter;
    }

    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        long long answer = 0;
        {
        long long int maxx = *max_element(time.begin(),time.end());
        long long int minn = *min_element(time.begin(),time.end());

        if(time.size()==1)
        {
            return 1LL*time[0]*totalTrips;
        }
        long long int start = 1;
        long long int end = maxx*totalTrips;

        long long int mid = start + (end-start)/2;

        while(start<end)
        {
            if(isValid(mid,time,totalTrips)>=totalTrips)
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
