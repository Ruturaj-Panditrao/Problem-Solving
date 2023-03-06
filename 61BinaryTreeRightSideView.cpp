/*
Problem Link :
https://leetcode.com/problems/binary-tree-right-side-view/description/
*/

class Solution 
{
public:

    void helper(TreeNode* root, int level, vector<int>&ds)
    {
        if(root == NULL)
        {
            return;
        }

        if(level == ds.size())
        {
            ds.push_back(root->val);
        }

        helper(root->right,level+1,ds);
        helper(root->left,level+1,ds);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ds;
        helper(root,0,ds);
        return ds;    
    }
};
