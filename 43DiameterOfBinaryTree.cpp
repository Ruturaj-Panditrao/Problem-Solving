/*
Problem Link :
https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

class Solution 
{
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }    

        int diameter = 0;
        height(root,diameter);
        return diameter;
    }

    int height(TreeNode* Node, int& diameter)
    {
        if(Node == NULL)
        {
            return 0;
        }

        int lh = height(Node->left, diameter);
        int rh = height(Node->right, diameter);

        diameter = max(diameter, lh+rh);

        return 1+max(lh,rh); 
    }
};
