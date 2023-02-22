/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/tree-traversal_981269?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

void inorder(BinaryTreeNode<int> * root, vector<int>&In)
{
    if(root==NULL) return;
    inorder(root->left,In);
    In.push_back(root->data);
    inorder(root->right,In);
}

void preorder(BinaryTreeNode<int> *root, vector<int>&Pre)
{
    if(root==NULL) return;
    Pre.push_back(root->data);
    preorder(root->left, Pre);
    preorder(root->right, Pre);
}

void postorder(BinaryTreeNode<int> *root, vector<int>&Post)
{
    if(root==NULL) return;
    postorder(root->left,Post);
    postorder(root->right,Post);
    Post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>>InPrePost;
    vector<int>In;
    vector<int>Pre;
    vector<int>Post;

    inorder(root,In);
    preorder(root,Pre);
    postorder(root,Post);

    InPrePost.push_back(In);
    InPrePost.push_back(Pre);
    InPrePost.push_back(Post);
    return InPrePost;
}
