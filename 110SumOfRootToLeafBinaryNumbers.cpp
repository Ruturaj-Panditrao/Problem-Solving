/*
Problem Link :
https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
*/

class Solution
{
public:
    long number = 0;
    void traverse(TreeNode* root, int curr)
    {
        if(root==NULL) return;
        curr = (curr<<1) | root->val;
        if(root->left == NULL && root->right ==NULL)
        {
            number += curr;
        }
        traverse(root->left,curr);
        traverse(root->right,curr);
    }
    long long int sumRootToLeaf(TreeNode* root) 
    {
        if(root == NULL) return 0;
        traverse(root,0);
        return number;
    }
};
