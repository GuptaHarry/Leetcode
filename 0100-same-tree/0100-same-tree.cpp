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
 bool find(TreeNode*p,TreeNode*q){

    // cases   p - N q- N , p-!N q-N , p-N q-!N , p-!N q-!N
    if(p==NULL && q == NULL)
    return 1;

    if(  (p && q==NULL) || (p==NULL && q)){
        // not same 
        // valid =0;
        return 0;
    }

    if(p->val != q->val)
    {
        // valid=0;
        return 0;
    }
return (
    find(p->left,q->left) &&
    find(p->right,q->right));

 }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // bool valid=1;
     return    find(p,q);
     
    }
};