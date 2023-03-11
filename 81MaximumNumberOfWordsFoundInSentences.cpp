/*
Problem Link :
https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
*/

class Solution
{
public:

    int wordCount(string s)
    {
        int count = 0;
        for(int i=0; i<s.length();i++)
        {
            if(s[i]==' ') count++;
        }
        return count+1;
    }
    int mostWordsFound(vector<string>& sentences) 
    {
        vector<int>w(sentences.size());
        for(int i=0; i<sentences.size();i++)
        {
            w[i] = wordCount(sentences[i]);
        }    

        return *max_element(w.begin(),w.end());
    }
};
