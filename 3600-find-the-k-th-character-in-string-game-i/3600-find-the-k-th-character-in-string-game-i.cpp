class Solution {
public:
    void find(string &ans, int k) { // pass by reference
        // base case
        if (ans.size() >= k)
            return;

        // build next half
        string temp = "";
        for (int i = 0; i < ans.size(); i++) {
            int c = ans[i];
            c == 'z' ? c = 'a' : c++;
            temp += (char)c;
        }

        ans += temp;

        // recursive call
        find(ans, k);
    }

    char kthCharacter(int k) {
        string ans = "a";
        find(ans, k);
        return ans[k-1];  // indexing fix
    }
};
