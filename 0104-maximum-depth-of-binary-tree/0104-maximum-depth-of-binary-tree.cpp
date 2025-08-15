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
  int find(TreeNode * root){

    if(root==NULL)
    return 0;

    return ( 1+ max( find(root->left), find(root->right)));
  }
    int maxDepth(TreeNode* root) {
        // find maximum nodes from left and right 
        return find(root);
    }
};