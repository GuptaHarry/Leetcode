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
void make(TreeNode * root){
    if(root== NULL)
    return ;

    TreeNode * temp = root->right;
    root->right = root->left;
    root->left = temp;

    make(root->left);
    make(root->right);
}

bool check(TreeNode * p, TreeNode *q){

    if(p==NULL && q==NULL)
    return 1;

    if( (p &&q==NULL) || (p==NULL && q))
    return 0;

    if(p->val!= q->val)
    return 0;

    return ( check(p->left,q->left) && check(p->right,q->right));
}
    bool isSymmetric(TreeNode* root) {
        // make the right one mirror and then check if left and right are  equal
        make(root->right);

        // check for equal left and right parts 
      return   check(root->left,root->right);
        }
};