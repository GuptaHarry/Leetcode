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
 bool find(TreeNode * root , int sum){
     //preorder approah 
     if(root ==NULL)
     return 0;

     sum-=root->val;
     if(sum==0 && root->left == NULL && root->right==NULL)
     return true;
     return (
     find(root->left,sum) ||
     find(root->right,sum));
 }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return find(root,targetSum);
    }
};