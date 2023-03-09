/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int,int>mp;
        for(int i=0; i<inorder.size();i++)
        {
            mp[inorder[i]]= i;
        }    

        TreeNode* root 
        = myRecursiveHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);

        return root;
    }

    TreeNode* myRecursiveHelper(vector<int>&preorder, int preStart, int preEnd, 
                                vector<int>&inorder, int inStart, int inEnd, map<int,int>&mp)
    {
        if(preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        root->left = myRecursiveHelper(preorder,preStart+1,preStart+numsLeft,
                                      inorder,inStart,inRoot-1,mp);
        root->right = myRecursiveHelper(preorder,preStart + numsLeft+1,preEnd,
                                      inorder,inRoot+1,inEnd,mp);
        return root;
    }
};
