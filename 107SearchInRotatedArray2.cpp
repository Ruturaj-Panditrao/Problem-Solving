/*
https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1
*/

class Solution 
{
  public:
    bool Search(int N, vector<int>& A, int Key)
    {
        for(int i=0; i<N; i++)
        {
            if(A[i]==Key)
            {
                return true;
            }
        }
        return false;
    }
};
