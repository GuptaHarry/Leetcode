class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = (long long)k * (k + 1) / 2;
		long long last = k + 1;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            if(nums[i] < last)
            {
                sum -= nums[i];
                sum += last++;
            }
        }
        return sum;
    }
};