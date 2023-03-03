/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/diameter-of-the-binary-tree_920552?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

int height(TreeNode<int> *root, int& diameter)
{
    if(root == NULL)
    {
        return 0;
    }

    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);

    diameter = max(diameter,lh+rh);

    return 1 + max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int diameter = 0;
    height(root,diameter);
    return diameter;
}
