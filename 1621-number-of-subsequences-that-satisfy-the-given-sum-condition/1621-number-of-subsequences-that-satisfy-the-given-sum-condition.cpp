class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int n = nums.size();

        // Precompute powers of 2 modulo mod
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2LL) % mod;
        }

        int s = 0, e = n - 1;
        int count = 0;

        while (s <= e) {
            if (nums[s] + nums[e] <= target) {
                count = (count + power[e - s]) % mod;
                s++;
            } else {
                e--;
            }
        }

        return count;
    }
};
