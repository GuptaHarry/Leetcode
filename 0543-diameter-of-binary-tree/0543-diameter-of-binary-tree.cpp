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
    int find(TreeNode * root, int&path){
        if(root==NULL)
        return 0;

        int l = find(root->left,path);
        int r = find(root->right,path);

        // update  
        path = max(path, l+r);

        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int path=0;
        find(root,path);
        return path;
    }
};