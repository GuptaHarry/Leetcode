class Solution {
public:
    
    int findLHS(vector<int>& nums) {
    unordered_map<int,int> freq;
    for (int num : nums) freq[num]++;
    
    int len = 0;
    for (auto &p : freq) {
        if (freq.count(p.first + 1)) {
            len = max(len, p.second + freq[p.first + 1]);
        }
    }
    return len;
}

};