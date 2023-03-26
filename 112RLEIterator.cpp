/*
Problem Link :
https://leetcode.com/problems/rle-iterator/
*/

class RLEIterator
{
public:
    vector<int>v;
    int i = 0;
    RLEIterator(vector<int>& encoding) {
        v = encoding;
    }
    int next(int n) {
        int last;
        while(n>0)
        {
            if(i>=v.size())
            {
                last = -1;
                break;
            }
            if(v[i]>=n)
            {
                last = v[i+1];
                v[i]-=n;
                break;
            }
            else
            {
                if(v[i]>0)
                {
                     n-=v[i];
                     v[i] = 0;
                }

                i+=2;
            }
        }   
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
