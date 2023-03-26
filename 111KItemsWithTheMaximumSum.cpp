/*
Problem Link :
https://leetcode.com/problems/k-items-with-the-maximum-sum/
*/

class Solution 
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        int pos = numOnes;
        int zero = numZeros;
        int neg = numNegOnes;
            int ans = 0;
        if(k<=pos)
        {
            ans = k;
        }
       else if(k<=pos+zero)
        {
            ans = pos;
        }
        else if(k>pos+zero)
        {
            ans = pos - (abs(pos+zero-k));
        }
        
      return ans;
            
    }
};
