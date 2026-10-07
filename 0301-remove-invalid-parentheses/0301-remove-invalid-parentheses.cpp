class Solution {
public:
    unordered_set<string> ans;

    void solve(string& s, int index, int left, int right,
               int removeLeft, int removeRight, string& temp) {

        if(index == s.size()) {
            if(left == 0 && right == 0 &&
               removeLeft == 0 && removeRight == 0) {
                ans.insert(temp);
            }
            return;
        }

        char c = s[index];


        if(c == '(') {
            if(removeLeft > 0) {
                solve(s, index + 1, left, right,
                      removeLeft - 1, removeRight, temp);
            }

      
            temp.push_back(c);
            solve(s, index + 1, left + 1, right,
                  removeLeft, removeRight, temp);
            temp.pop_back();
        }

        else if(c == ')') {

    
            if(removeRight > 0) {
                solve(s, index + 1, left, right,
                      removeLeft, removeRight - 1, temp);
            }

           
            if(left > 0) {
                temp.push_back(c);
                solve(s, index + 1, left - 1, right,
                      removeLeft, removeRight, temp);
                temp.pop_back();
            }
        }

        else {
            temp.push_back(c);
            solve(s, index + 1, left, right,
                  removeLeft, removeRight, temp);
            temp.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int removeLeft = 0;
        int removeRight = 0;

        for(char c : s) {
            if(c == '(') {
                removeLeft++;
            }
            else if(c == ')') {
                if(removeLeft > 0)
                    removeLeft--;
                else
                    removeRight++;
            }
        }

        string temp;

        solve(s, 0, 0, 0,
              removeLeft, removeRight, temp);

        return vector<string>(ans.begin(), ans.end());
    }
};