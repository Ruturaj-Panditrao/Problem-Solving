/*
Problem Link
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
*/

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>answer;
        if(root == NULL)
        {
            return answer;
        }    

        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty())
        {
            int loopsize = q.size();
            vector<int>level(loopsize);
            for(int i=0; i<loopsize; i++)
            {
              TreeNode* Node = q.front();
              q.pop();

              int index = leftToRight ? i : loopsize-i-1;
              level[index] = Node->val;
              
              if(Node->left)
              {
                  q.push(Node->left);
              }
              if(Node->right)
              {
                  q.push(Node->right);
              }
            }

            leftToRight = !leftToRight;
            answer.push_back(level);
        }

        return answer;
    }
};
