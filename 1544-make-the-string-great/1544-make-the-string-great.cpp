class Solution {
public:
    string solve(string s) {
        if (s.empty())
            return "";

        char current = s[0];
        string rest = solve(s.substr(1));

        if (!rest.empty() && abs(current - rest[0]) == 32) {
            rest.erase(0, 1);
            return rest;
        }
        return current + rest;
    }

    string makeGood(string s) { return solve(s); }
};