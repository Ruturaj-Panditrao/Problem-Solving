/*
Practice Link :
https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*/

class Solution
 {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>postorder;
        if(root == NULL)
        {
            return postorder;
        }    

        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        st1.push(root);

        while(!st1.empty())
        {
            TreeNode* top = st1.top();
            st1.pop();
            st2.push(top);

            if(top->left!=NULL)
            {
                st1.push(top->left);
            }
            if(top->right!=NULL)
            {
                st1.push(top->right);
            }
        }

        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};
