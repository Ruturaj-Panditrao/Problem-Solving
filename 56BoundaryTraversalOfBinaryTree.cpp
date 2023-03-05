/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

bool isLeaf(TreeNode<int>* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>&res)
{
    TreeNode<int>* curr = root->left;
    while(curr!=NULL)
    {
        if(!isLeaf(curr))
        {
            res.push_back(curr->data);
        }

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeafNodes(TreeNode<int>* root, vector<int>&res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeafNodes(root->left,res);
    if(root->right) addLeafNodes(root->right,res);
}

void addRightBoundary(TreeNode<int>* root, vector<int>&res)
{
    TreeNode<int>* curr = root->right;
    vector<int>temp;

    while(curr!=NULL)
    {
        if(!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1; i>=0; i--)
    {
        res.push_back(temp[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int>res;
    if(root == NULL) return res;

    if(!isLeaf(root))
    {
        res.push_back(root->data);
    }

    addLeftBoundary(root,res);
    addLeafNodes(root,res);
    addRightBoundary(root,res);
    return res;

}
