class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> a1(26, 0), a2(26, 0);

        // frequency of s1
        for (char c : s1) a1[c - 'a']++;

        int s = 0, e = 0;
        while (e < s2.size()) {
            // add current char
            a2[s2[e] - 'a']++;

            // if window size > s1.size(), shrink from left
            if (e - s + 1 > s1.size()) {
                a2[s2[s] - 'a']--;
                s++;
            }

            // if window size == s1.size(), compare
            if (e - s + 1 == s1.size() && a1 == a2) {
                return true;
            }

            e++;
        }
        return false;
    }
};
