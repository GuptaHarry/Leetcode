class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> freq(101, 0); // index 0 â -50, index 100 â 50

        int s = 0; // left pointer
        for (int e = 0; e < n; e++) { // right pointer
            // add new element
            freq[nums[e] + 50]++;

            // when window size == k
            if (e - s + 1 == k) {
                // find x-th smallest
                int count = 0;
                int val = 0;
                for (int v = -50; v <= 50; v++) {
                    count += freq[v + 50];
                    if (count >= x) {
                        val = v;
                        break;
                    }
                }

                ans.push_back(val < 0 ? val : 0);

                // remove outgoing element
                freq[nums[s] + 50]--;
                s++;
            }
        }
        return ans;
    }
};
