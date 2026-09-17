class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;

        for (int x : nums) {
            ans += freq[x];
            freq[x]++;
        }
        return ans;
    }
};