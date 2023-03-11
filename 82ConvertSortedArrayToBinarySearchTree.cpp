/*
Problem Link :
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*/

class Solution 
{
public:
    
    TreeNode* createBST(int left, int right, vector<int>&nums)
    {
        if(left>right) return NULL;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(left,mid-1,nums);
        root->right = createBST(mid+1,right,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* root = createBST(0,nums.size()-1,nums);
        return root;    
    }
};
