/*
Problem Link 
https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q) 
{
        if(root == NULL || root == P || root == Q)
        {
            return root;
        }

        TreeNode<int>* left = LCAinaBST(root->left,P,Q);
        TreeNode<int>* right = LCAinaBST(root->right,P,Q);

        if(left == NULL) return right;
        if(right == NULL) return left;
        else return root;
}
