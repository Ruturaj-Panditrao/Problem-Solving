/*
Problem Link :
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
*/

class Solution 
{
public:

    TreeNode* createBST(int left, int right, vector<int>&nodes)
    {
        if(left > right) return NULL;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = createBST(left,mid-1,nodes);
        root->right = createBST(mid+1,right,nodes);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int>nodes;
        while(head)
        {
            nodes.push_back(head->val);
            head = head->next;
        }
        // Construct BS Tree From Inorder Traversal
        int left = 0;
        int right = nodes.size()-1;
        int mid = (left+right)/2;
        TreeNode* root = createBST(0,nodes.size()-1,nodes);
        return root;
    }
};
