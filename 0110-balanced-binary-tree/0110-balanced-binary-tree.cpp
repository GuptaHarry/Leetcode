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
 int height(TreeNode * root){
    if(root==NULL)
    return 0;

    return 1+ max( height(root->left),height(root->right));
 }
   bool find(TreeNode * root){
      if(root==NULL)
      return true;

      // find L & R height
      int L = height(root->left);
      int R = height(root->right);
      if( abs(L-R)>1)
      return false;
 
     return ( find(root->left) && find(root->right));
   }
    bool isBalanced(TreeNode* root) {
        

        return find(root);
    }
};