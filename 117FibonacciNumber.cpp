/*
Problem Link :
https://leetcode.com/problems/fibonacci-number/description/
*/

// Method 1
vector<int> qb(31,-1);
class Solution
{
public:
    int fib(int n) 
    {
        if(n==0) return 0;
        if(n==1) return 1;

        if(qb[n]!= -1) return qb[n];
        return qb[n] = fib(n-1) + fib(n-2);
    }
};

// Method 2
class Solution
{
public:
    int fib(int n) 
    {
        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-1) + fib(n-2);
    }
};
