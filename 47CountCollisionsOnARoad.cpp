/*
Problem Link :
https://leetcode.com/problems/count-collisions-on-a-road/description/
*/

class Solution 
{
public:
    int countCollisions(string directions)
    {
        // Moving from Left to Right
        // Detect RL collisions

        long long int counter = 0;

        for(int i=0; i<directions.size(); i++)
        {
            if(i+1 < directions.size() && directions[i]=='R' && directions[i+1]=='L')
            {
                counter+=2;
                directions[i] = 'S';
                directions[i+1] = 'S';
            }
            if(i+1< directions.size() && directions[i]=='R' && directions[i+1]=='S')
            {
                counter+=1;
                directions[i]= 'S';
            }
            if(i+1 < directions.size() && directions[i]=='S' && directions[i+1]=='L')
            {
                counter+=1;
                directions[i+1] = 'S';
            }
        }    

        for(int i=directions.size()-1; i>0; i--)
        {
            if(directions[i]=='S' && directions[i-1]=='R')
            {
                counter+=1;
                directions[i-1]='S';
            }

        }
        return counter;
    }
};
