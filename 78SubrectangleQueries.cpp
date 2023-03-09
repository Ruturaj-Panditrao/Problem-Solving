/*
Problem Link :
https://leetcode.com/problems/subrectangle-queries/description/
*/

class SubrectangleQueries 
{
public:

    vector<vector<int>>vec;
    SubrectangleQueries(vector<vector<int>>& rectangle)
    {
        vec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        for(int i= col1; i<=col2; i++)
        {
            for(int j=row1; j<=row2; j++)
            {
                vec[j][i] = newValue;
            }
        }
    }
    
    int getValue(int row, int col)
    {
        return vec[row][col];    
    }
};
