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
 void find(TreeNode * root ,int &sum,bool isLeft){
    if(root==NULL)
    return ;
if(!root->left && !root->right && isLeft  ){
        sum+=root->val;
        return;
    }
      


      find(root->left,sum,true);
    find(root->right,sum,false);
    
 }
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum=0;
        find(root,sum,false);
        return sum;
    }
};