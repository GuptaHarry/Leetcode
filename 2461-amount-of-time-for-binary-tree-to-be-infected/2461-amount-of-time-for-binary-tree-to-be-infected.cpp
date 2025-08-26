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
    int amountOfTime(TreeNode* root, int target) {
        

        unordered_map<TreeNode * , TreeNode * >m;
        m[root]=NULL;
        queue<TreeNode* >q;
        q.push(root);
        TreeNode * temp;
        while(!q.empty()){
            // no dispersion by size is required 
            TreeNode * curr= q.front();
            q.pop();
            
            if(curr->val==target)
            temp=curr;
            
            if(curr->left){
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                m[curr->right]=curr;
                q.push(curr->right);
            }
            
        }
        
        // bool array 
        unordered_map<TreeNode* ,bool>m2;
        m2[temp]=true;
        q.push(temp);
        
        int ans=0;
        while(!q.empty()){
          int s=q.size();
          while(s--){
              TreeNode * curr=q.front();
              q.pop();
              m2[curr]=true;
              if(curr->left && !m2[curr->left]){
                  q.push(curr->left);
              }
              if(curr->right && !m2[curr->right]){
                  q.push(curr->right);
              }
              // also push their parent node of the targe 
              if(m[curr]!=NULL && !m2[m[curr]]){
                  q.push(m[curr]);
              }
              
          }
          ans++;
        
        }
        
        return ans-1;  // bcz after the last level no nned ot burn that 
        
    }
};