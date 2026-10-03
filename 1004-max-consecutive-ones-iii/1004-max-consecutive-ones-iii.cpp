class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxOnes = 0;
        int Zctr = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0)
                Zctr++;
            while (Zctr > k) {
                if (nums[l] == 0)
                    Zctr--;
                l++;
            }
            maxOnes = max(maxOnes, r - l + 1);
        }
        return maxOnes;
    }
};