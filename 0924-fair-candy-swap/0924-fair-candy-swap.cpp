class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = 0, sumB = 0;
        for (int a : aliceSizes) sumA += a;
        for (int b : bobSizes) sumB += b;
        
        int delta = (sumA - sumB) / 2;
        unordered_set<int> setB(bobSizes.begin(), bobSizes.end());
        
        for (int a : aliceSizes) {
            int b = a - delta;
            if (setB.count(b)) return {a, b};
        }
        return {};
    }
};
