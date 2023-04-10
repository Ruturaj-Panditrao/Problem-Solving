/*
Problem Link :
https://leetcode.com/problems/decode-the-message/description/
*/

class Solution 
{
public:
    string decodeMessage(string key, string message) 
    {
        map<char,char>mp;
        char ch = 'a';
        for(auto it : key)
        {
            if(it == ' ') continue;
            if(mp.find(it)==mp.end())
            {
            mp[it] = ch;
            ch++;
            }
        }    
       string ans = "";
       for(auto it : message)
       {
           if(it == ' ') ans+=" ";
           else ans+=mp[it];
       }
       return ans;
    }
};
