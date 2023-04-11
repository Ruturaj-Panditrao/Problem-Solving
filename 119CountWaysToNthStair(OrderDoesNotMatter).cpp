/*
Problem Link :
https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1
*/

class Solution
{
	public:
		int nthStair(int n)
		{
		    // 1 -> 1
		    // 2 -> 2
		    // 3 -> 2
		    // 4 -> 3
		    // 5 -> 3
		    
		    // Only increments in case of Even Numbers
		    return (1 + n/2);
		}
};
