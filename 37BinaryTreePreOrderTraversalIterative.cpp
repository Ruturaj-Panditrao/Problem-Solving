/*
Problem Link :
https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }    
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* Node = st.top();
            st.pop();
            ans.push_back(Node->val);
            if(Node->right != NULL)
            {
                st.push(Node->right);
            }
            if(Node->left != NULL)
            {
                st.push(Node->left);
            }
        }
        return ans;
    }
};
