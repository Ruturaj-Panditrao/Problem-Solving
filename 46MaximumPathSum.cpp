/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/binary-tree-maximum-path-sum_1280142?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

int height(TreeNode<int>*Node, int&maxi)
{
    if(Node==NULL)
    {
        return 0;
    }

    int left = max(0,height(Node->left,maxi));
    int right = max(0,height(Node->right,maxi));

    maxi = max(maxi,left + Node->val + right);

    return Node->val + max(left,right);
}

int maxPathSum(TreeNode<int>* root)
{
	int maxi = INT_MIN;
    height(root,maxi);
    return maxi;
}
