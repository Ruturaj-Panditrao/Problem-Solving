/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/tree-symmetricity_630426?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

bool helper(BinaryTreeNode<int>* left, BinaryTreeNode<int>*right)
{
    if(left == NULL || right == NULL)
    {
        return left == right;
    }

    if(left->data != right->data)
    {
        return false;
    }

    return helper(left->left, right->right) && helper(left->right,right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root == NULL || helper(root->left,root->right);
}
