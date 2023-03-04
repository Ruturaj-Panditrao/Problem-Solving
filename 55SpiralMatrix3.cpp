/*
Problem Link :
https://leetcode.com/problems/spiral-matrix-iii/description/
*/

class Solution 
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) 
    {
        long long int counter = rows*cols;
        vector<vector<int>>ans;
        long long int right = 1;
        long long int down = 1;
        long long int left = 2;
        long long int up = 2;
        vector<int>begg;
        begg.push_back(rStart);
        begg.push_back(cStart);
        ans.push_back(begg);
        counter--;

        // cout<<"("<<rStart<<","<<cStart<<")"<<endl;
        while(counter!=0)
        {   
           
            // Right
            // Down
            // Left
            // Up

            for(int i=1; i<=right;i++)
            {   
                vector<int>temp;
                cStart+=1;
                if(counter==0)
                {
                        break;
                }
                if(rStart < rows && rStart >=0 && cStart<cols && cStart >=0)
                {
                    temp.push_back(rStart);
                    temp.push_back(cStart);
                    ans.push_back(temp);
                    counter--;
                    // cout<<"("<<rStart<<","<<cStart<<")"<<endl;
                    if(counter==0)
                    {
                        break;
                    }
                }
               
            }

            if(counter==0)
                    {
                        break;
                    }

            right+=2;

           for(int i=1; i<=down;i++)
            {   
                vector<int>temp;
                 rStart+=1;
               if(counter==0)
                    {
                        break;
                    }
                if(rStart < rows && rStart >=0 && cStart<cols && cStart >=0)
                {
                    temp.push_back(rStart);
                    temp.push_back(cStart);
                    ans.push_back(temp);
                    counter--;
                    // cout<<"("<<rStart<<","<<cStart<<")"<<endl;
                    if(counter==0)
                    {
                        break;
                    }
                }
                
            }

            if(counter==0)
                    {
                        break;
                    }

            down+=2;

            for(int i=1; i<=left;i++)
            {   
                vector<int>temp;
                cStart-=1;
                if(counter==0)
                    {
                        break;
                    }
                // cout<<"("<<rStart<<","<<cStart<<")"<<endl;
                if(rStart < rows && rStart >=0 && cStart<cols && cStart >=0)
                {
                    temp.push_back(rStart);
                    temp.push_back(cStart);
                    ans.push_back(temp);
                    counter--;
                    if(counter==0)
                    {
                        break;
                    }
                }
                
            }

            if(counter==0)
                    {
                        break;
                    }

            left+=2;

            for(int i=1; i<=up;i++)
            {   
                vector<int>temp;
                rStart-=1;
                if(counter==0)
                    {
                        break;
                    }
                if(rStart < rows && rStart >=0 && cStart<cols && cStart >=0)
                {
                    // cout<<"("<<rStart<<","<<cStart<<")"<<endl;
                    temp.push_back(rStart);
                    temp.push_back(cStart);
                    ans.push_back(temp);
                    counter--;
                    if(counter==0)
                    {
                        break;
                    }
                } 
            }

            if(counter==0)
                    {
                        break;
                    }

            up+=2;

        }

        return ans;
    }
};
