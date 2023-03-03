/*
Problem Link :
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
*/

class Solution 
{
public:
    int maxPathSum(TreeNode* root)
    {
        int maxi = INT_MIN;
        height(root,maxi);
        return maxi;
    }

    int height(TreeNode* node, int& maxi)
    {
        if(node==NULL)
        {
            return 0;
        }

        int left = max(0,height(node->left,maxi));
        int right = max(0,height(node->right,maxi));

        maxi = max(maxi,left+ node->val+ right);

        return node->val + max(left,right);
    }
};
