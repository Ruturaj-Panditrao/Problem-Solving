/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/left-view-of-binary-tree_625707?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

void helper(BinaryTreeNode<int> *root, int level, vector<int>&ds)
{
    if(root == NULL)
    {
        return;
    }

    if(level == ds.size())
    {
        ds.push_back(root->data);
    }

    helper(root->left,level+1,ds);
    helper(root->right,level+1,ds);

}
void printLeftView(BinaryTreeNode<int> *root)
{
   vector<int>ds;
   helper(root,0,ds);
   for(auto it : ds)
   {
       cout<<it<<" ";
   }
}
