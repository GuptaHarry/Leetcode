class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        // Find first non-negative number (>= 0)
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) left = mid + 1;
            else right = mid - 1;
        }
        int neg = left; // count of negatives

        // Find first positive number (> 0)
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= 0) left = mid + 1;
            else right = mid - 1;
        }
        int pos = n - left; // count of positives

        return max(neg, pos);
    }
};
