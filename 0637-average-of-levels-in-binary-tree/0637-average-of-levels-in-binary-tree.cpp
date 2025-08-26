/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double>ans;
        queue<TreeNode * >q;
        q.push(root);
        while(!q.empty()){
          
          int s =  q.size();
          int count=0;
          double avg =0;
          while(s--){
            TreeNode * curr = q.front();
            q.pop();
            count++;
            avg+=curr->val;
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);

          }
          ans.push_back(avg/count);

        }
        return ans;
    }
};