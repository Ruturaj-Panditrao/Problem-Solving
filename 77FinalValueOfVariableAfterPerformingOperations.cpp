/*
Problem Link :
https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/
*/

class Solution 
{
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        long long int val = 0;

        for(int i=0; i<operations.size();i++)
        {
            if(operations[i]=="X++") val++;
            if(operations[i]=="++X") val++;
            if(operations[i]=="--X") val--;
            if(operations[i]=="X--") val--;
        }

        return val;
    }   
};
