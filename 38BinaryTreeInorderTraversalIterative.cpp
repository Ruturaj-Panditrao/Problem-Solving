/*
Problem Link :
https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*/

class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL) 
        {
            return ans;
        }    

        TreeNode* Node = root;
        stack<TreeNode*>st;
        while(true)
        {
            if(Node!=NULL)
            {
                st.push(Node);
                Node = Node->left;
            }
            else if(Node == NULL)
            {
                if(st.empty())
                {
                    break;
                }
                Node = st.top();
                st.pop();
                ans.push_back(Node->val);
                Node = Node->right;
            }
        }
        return ans;
    }
};
