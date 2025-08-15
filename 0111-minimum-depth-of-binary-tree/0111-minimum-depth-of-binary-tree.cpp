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

     int l = find(root->left);
     int r = find(root->right);
     if(l==0)
     return 1+r;
     if(r==0)
     return 1+l;
     else
     return 1+min(l,r);
    // return 1 + min( , find(root->right));
}
    int minDepth(TreeNode* root) {
       return find(root);   
    }
};