/*
Problem Link :
https://leetcode.com/problems/excel-sheet-column-number/description/
*/

class Solution 
{
public:
    int titleToNumber(string columnTitle) 
    {
        long long int res = 0;
        long long int j = 0;
        for(int i = columnTitle.length()-1; i>=0; i--)
        {
            res += (columnTitle[i] - 65 + 1)* pow(26,j);
            j++;
        }    

        return res;
    }
};
