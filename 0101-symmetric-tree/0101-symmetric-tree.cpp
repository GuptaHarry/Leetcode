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
    bool isSymmetric(TreeNode* root) {
        
        // symmetric approach 
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* leftCh = q.front();
            q.pop();
            TreeNode* RightCh = q.front();
            q.pop();

            // check condtion 
            if( leftCh == NULL && RightCh ==NULL)
            continue;
            // do nothhing
            if( (leftCh && RightCh==NULL ) || (leftCh==NULL && RightCh))
            return 0;

            if(leftCh->val !=RightCh->val)
            return 0;

            q.push(leftCh->left);
            q.push(RightCh->right);

            q.push(leftCh->right);
            q.push(RightCh->left);
            
        }
        return 1;
    }
};