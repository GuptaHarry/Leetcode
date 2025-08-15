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
TreeNode * find(int s,int e , vector<int>&nums){

    if(s<0 || e==nums.size()|| s>e)
    return NULL;

    int mid = (s+e)/2;
    TreeNode * root = new TreeNode(nums[mid]);
    root->left=find(s,mid-1,nums);
    root->right=find(mid+1,e,nums);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // construct bst 
        int s = 0, e = nums.size()-1;
        TreeNode * root = find(s,e,nums);
        return root;
    }
};