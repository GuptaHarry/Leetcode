class Solution {
public:
    int specialArray(vector<int>& nums) {
        int s = 0, e = 1000; // possible x range

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int count = 0;

            for (int num : nums)
                if (num >= mid) count++;

            if (count == mid)
                return mid;           // found the special value
            else if (count > mid)
                s = mid + 1;          // need larger x
            else
                e = mid - 1;          // need smaller x
        }

        return -1; // no valid x
    }
};
