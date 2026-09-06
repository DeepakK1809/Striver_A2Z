class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
         if (nums.size() == 0) return 0; 
        int longest = 1;

        for (int x : s) {
            if (s.find(x - 1) == s.end()){

                int curr = x;
                int len = 1;

                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};