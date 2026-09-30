class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        int ctr = 0;

        for (char c : s) {
            if (c == '(')
                ctr++;
            else {
                ctr--;

                if (ctr < 0)
                    return false;
            }
        }

        return ctr == 0;
    }
    void solve(string s, int n) {
        if (s.size() == 2 * n) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        s.push_back('(');
        solve(s, n);
        s.pop_back();
        s.push_back(')');
        solve(s, n);
        s.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        solve("", n);
        return ans;
    }
};