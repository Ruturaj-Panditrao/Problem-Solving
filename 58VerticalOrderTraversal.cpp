/*
Problem Link :
https://www.codingninjas.com/codestudio/problems/vertical-order-traversal_920533?leftPanelTab=0
*/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    map<int,map<int,vector<int>>>dataStruct;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        int loopsize = q.size();
        for(int i=0; i<loopsize; i++)
        {
            auto p = q.front();
            q.pop();
            TreeNode<int>* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            dataStruct[vertical][level].push_back(node->data);

            if(node->left)
            {
                q.push({node->left,{vertical-1,level+1}});
            }
            if(node->right)
            {
                q.push({node->right,{vertical+1,level+1}});
            }
        }
    }

     vector<int>temp;
    for(auto p : dataStruct)
    {
       for(auto q : p.second)
       {
           for(auto r : q.second)
           {
               temp.push_back(r);
           }
       }
    }

    return temp;
}
