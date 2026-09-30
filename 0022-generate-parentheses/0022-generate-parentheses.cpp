class Solution {
public:
    vector<string> ans;

    void solve(string s, int n, int open, int close) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            solve(s,n,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            solve(s,n,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, 0, 0);
        return ans;
    }
};