/*
Problem Link :
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
*/

class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        // Queue Data Structure
        // Node Pointer, Vertical, Level

        queue<pair<TreeNode*,pair<int,int>>>q;

        // Custom Data Structure that,
        // Maps each Vertical to a Level,
        // Each (Vertical,Level) to Nodes in that Level

        map<int,map<int,multiset<int>>>dataStruct;

        q.push({root,{0,0}});
        // Initially Set the Vertical & Level to 0

        while(!q.empty())
        {
            int loopsize = q.size();
            for(int i=0; i<loopsize;i++)
            {
            auto p = q.front();
            q.pop();

            TreeNode* nodeptr = p.first;
            int nodeval = nodeptr->val;
            int vertical = p.second.first;
            int level = p.second.second;

            // Accessing All the Attributes of the Queue's Front Element
            // Now we can insert them into our Custom Data Structure

            dataStruct[vertical][level].insert(nodeval);

            // Now we perform the usual Level Order Traversal
            // While Moving Left, Vertical decreases by 1 
            // But since we move down, Level increases by 1

            if(nodeptr->left)
            {
                q.push({nodeptr->left,{vertical-1,level+1}});
            }

            // While Moving Right, Vertical increases by 1
            // But since we move down, Level increases by 1
            if(nodeptr->right)
            {
                q.push({nodeptr->right,{vertical+1,level+1}});
            }
            }
        }

        vector<vector<int>>ans;

        for(auto p : dataStruct)
        {
            vector<int>temp;
            for(auto q : p.second)
            {
               temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            // We insert the Node values only into the answer vector
            ans.push_back(temp);
        }    

        return ans;
    }
};
