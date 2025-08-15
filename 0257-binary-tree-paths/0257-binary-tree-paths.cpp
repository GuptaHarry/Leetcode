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
void rec(TreeNode* root,vector<string>&ans,string temp)
{
    if(!root)
    return;
    temp+=to_string(root->val) + "->";
    if(!root->left && !root->right)
    {
        temp.pop_back();
        temp.pop_back();
        ans.push_back(temp);
        return ;
    }
    rec(root->left,ans,temp);
    rec(root->right,ans,temp);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
        return {};
        vector<string>ans;
        rec(root,ans,"");
        return ans;
    }
};