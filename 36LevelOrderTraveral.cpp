/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/level-order-traversal_796002?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
   vector<int>ans;
   if(root == NULL)
   {
       return ans;
   }
   queue<BinaryTreeNode<int>*>q;
   q.push(root);
   while(!q.empty())
   {
       int loopsize = q.size();
       for(int i=0; i<loopsize; i++)
       {
           BinaryTreeNode<int>* Node = q.front();
           q.pop();
           if(Node->left != NULL)
           {
               q.push(Node->left);
           }
           if(Node->right != NULL)
           {
               q.push(Node->right);
           }
           ans.push_back(Node->val);
       }
   }
   return ans;
}
