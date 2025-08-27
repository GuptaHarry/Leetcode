class Solution {
public:
    int find(TreeNode* root, int &sum) {
        if (!root) return 0;

        int leftSum = std::max(0, find(root->left, sum));
        int rightSum = std::max(0, find(root->right, sum));

        // update global maximum path (root + left + right)
        sum = std::max(sum, root->val + leftSum + rightSum);

        // return max downward path through one child
        return root->val + std::max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        find(root, sum);
        return sum;
    }
};
