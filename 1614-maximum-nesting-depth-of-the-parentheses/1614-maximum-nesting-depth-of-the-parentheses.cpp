class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int ctr = 0;

        for (char c : s) {
            if (c == '(') {
                ctr++;
                mx = max(mx, ctr);
            } else if (c == ')') {
                ctr--;
            }
        }
        return mx;
    }
};
