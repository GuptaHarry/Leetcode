class Solution {
public:
    void sum(vector<int>& nums, int i, long long ans, vector<vector<int>>& res) {

        for(int j = i + 1; j < nums.size() - 2; j++) {

            // skip duplicate j
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;

            int s = j + 1;
            int e = nums.size() - 1;
            long long t = ans - nums[j];

            while(s < e) {
                long long curr = nums[s] + nums[e];

                if(curr == t) {
                    res.push_back({nums[i], nums[j], nums[s], nums[e]});

                    // skip duplicates for s
                    int last_s = nums[s];
                    while(s < e && nums[s] == last_s) s++;

                    // skip duplicates for e
                    int last_e = nums[e];
                    while(s < e && nums[e] == last_e) e--;
                }
                else if(curr < t) {
                    s++;
                }
                else {
                    e--;
                }
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < (int)nums.size() - 3; i++) {

            // skip duplicate i
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            long long ans = (long long)target - nums[i];
            sum(nums, i, ans, res);
        }
        return res;
    }
};
