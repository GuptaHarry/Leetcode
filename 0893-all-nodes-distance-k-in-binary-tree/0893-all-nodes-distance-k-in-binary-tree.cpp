/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
 void find(TreeNode * root , int target, TreeNode * &node){
      if(!root)
      return ;
      if(root->val == target){
          node = root;
          return;
          
      }
      find(root->left,target,node);
      find(root->right,target,node);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    
        // return the sorted vector of all nodes at k dist
        
        //  find the base node first and then retur n 
        // TreeNode * node = NULL;
        // find(root,target,node);
        // apply bfs from the target node 
        // need parent pointers also
        unordered_map<TreeNode * , TreeNode *>m;
        unordered_map<TreeNode * , bool>visited;
         queue<TreeNode*>q;
        m[root]=NULL;
        // visited[root]=true;
        q.push(root);
        while(!q.empty()){
            
            TreeNode * curr = q.front();
            q.pop();
            
            if(curr->left){
                m[curr->left]=curr;
                q.push(curr->left);
            }
            
            if(curr->right)
            {
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
        
       
        q.push(target);
        vector<int>ans;
        
        while(!q.empty())
        {
            
            int s = q.size();
            // k==0?0:k;
            while(s--){
                if(k==0){
                    
                    TreeNode * curr = q.front();
                    q.pop();
                    if(!visited[curr])
                    {visited[curr]=true;
                    
                    ans.push_back(curr->val);
                    }
                }
                else{
                    
                  TreeNode * curr = q.front();
                  q.pop();
                  visited[curr]=true;
                  
                  if(curr->left)
                  q.push(curr->left);
                  if(curr->right)
                  q.push(curr->right);
                  // push parent also 
                  
                  if(m[curr]!=NULL && !visited[m[curr]]){
                      q.push(m[curr]);
                  }
                }
                
                
               
            }
            k--;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};