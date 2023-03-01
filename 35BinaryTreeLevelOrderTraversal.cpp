/*
Problem Link :
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;

        if(root == NULL)
        {
            return ans;
        }    

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>level;

            int loopsize = q.size();
            for(int i=0; i<loopsize; i++)
            {
                TreeNode* Node = q.front();
                q.pop();

                if(Node->left != NULL)
                {
                    q.push(Node->left);
                }
                if(Node->right != NULL)
                {
                    q.push(Node->right);
                }

                level.push_back(Node->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};
