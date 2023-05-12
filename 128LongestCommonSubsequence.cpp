/*
Problem Link 
https://leetcode.com/problems/longest-common-subsequence/description/
*/

// RECURSIVE
class Solution 
{
public:

    int f(int index1, int index2, string& text1, string& text2)
    {
        if(index1<0 || index2<0) return 0;

        // Match

        if(text1[index1]==text2[index2])
        return 1 + f(index1-1,index2-1,text1,text2);

        // Not Match

        else return max(f(index1-1,index2,text1,text2),f(index1,index2-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length();
        int m = text2.length();
        return f(n-1,m-1,text1,text2);
    }
};
