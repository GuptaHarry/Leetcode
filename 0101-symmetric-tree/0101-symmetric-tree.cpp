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

 bool check(TreeNode * p , TreeNode * q){

    // check for NULL
    if(p== NULL && q==NULL)
    return 1;

    if( (p && q==NULL) || (p==NULL &&q))
    return 0;

    /// for values 
    if( p->val !=q->val)
    return 0;

    return ( check(p->left,q->right) && check(p->right,q->left));
 }
    bool isSymmetric(TreeNode* root) {
       return  check(root->left,root->right);
    }
};