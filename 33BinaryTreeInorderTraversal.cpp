/*
Problem Link :
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

class Solution 
{
public:
    void inorder(vector<int>&ans, TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(ans,root->left);
        ans.push_back(root->val);
        inorder(ans,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        inorder(ans,root);
        return ans;
    }
};
