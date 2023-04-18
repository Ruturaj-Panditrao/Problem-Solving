/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
*/

#include <bits/stdc++.h> 
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int>temp1;
    vector<int>temp2;
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(int i=0; i<valueInHouse.size();i++)
    {
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }

    long long int ans1 = solve(temp1);
    long long int ans2 = solve(temp2);
    return max(ans1,ans2);
}
