/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/spiral-order-traversal-of-a-binary-tree_630521?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
*/

vector<int> spiralOrder(BinaryTreeNode<int> *root)
{
	vector<vector<int>>answer;
    vector<int>sans;
    if(root == NULL)
    {
        return sans;
    }

    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty())
    {
        int loopsize = q.size();
        vector<int>level(loopsize);
        
        for (int i = 0; i < loopsize; i++) 
        {
          BinaryTreeNode<int> *Node = q.front();
          q.pop();

          int index = leftToRight ? i : loopsize-i-1;
          level[index] = Node->data;
          
          if(Node->left)
          {
              q.push(Node->left);
          }
          if(Node->right)
          {
              q.push(Node->right);
          }
        }

        answer.push_back(level);
        leftToRight = !leftToRight;
    }

    for(int i=0; i<answer.size();i++)
    {
        for(auto it : answer[i])
        {
            sans.push_back(it);
        }
    }

    return sans;
}
