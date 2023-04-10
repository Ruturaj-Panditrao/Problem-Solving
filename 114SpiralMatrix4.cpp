/*
Problem Link :
https://leetcode.com/problems/spiral-matrix-iv/description/
*/

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(vector<vector<int>>(m,vector<int>(n,-10)));
        int cur_i = 0, cur_j = -1, values = 0;
        int right = n, down = m-1, left = n-1, up = m-2;
        while(values <= m*n) {
            for(int i=1;i<=right;i++) {
                cur_j++;
                if(head==NULL) {
                    ans[cur_i][cur_j] = -1;
                    // cout<<-1<<endl;
                }
                else{
                    ans[cur_i][cur_j] = head -> val;
                    // cout<<head->val<<endl;
                    head = head -> next;
                }
            }

            values += right;

            if(values >= m*n) break;

            if(cur_j > n-1) {
                cur_j--;
            }

            for(int i=1;i<=down;i++) {
                cur_i++;
                if(head==NULL) {
                    ans[cur_i][cur_j] = -1;
                    // cout<<-1<<endl;
                }
                else{
                    ans[cur_i][cur_j] = head -> val;
                    // cout<<head->val<<endl;
                    head = head -> next;
                }
            }

            values += down;

            if(values >= m*n) break;

            if(cur_i > m-1) {
                cur_i--;
            }

            for(int i=1;i<=left;i++) {
                cur_j--;
                if(head == NULL) {
                    ans[cur_i][cur_j] = -1;
                }
                else{
                    ans[cur_i][cur_j] = head -> val;
                    head = head -> next;
                }
            }

            values += left;

            if(values >= m*n) break;

            if(cur_j < 0) {
                cur_j++;
            }

            for(int i=1;i<=up;i++) {
                cur_i--;
                if(head == NULL) {
                    ans[cur_i][cur_j] = -1;
                }
                else{
                    ans[cur_i][cur_j] = head -> val;
                    head = head -> next;
                }
            }

            values += up;

            if(values >= m*n) break;

            if(cur_i < 0) {
                cur_i++;
            }

            right=left-1;
            down = up-1;
            left = right-1;
            up = down-1;
        }

        return ans;
    }
};
