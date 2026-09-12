class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0;
        int ctr1 = 0, ctr2 = 0;
        int n = nums.size();

        for (int x : nums) {
            if (ctr1 > 0 && x == cand1) {
                ctr1++;
            } else if (ctr2 > 0 && x == cand2) {
                ctr2++;
            } else if (ctr1 == 0) {
                cand1 = x;
                ctr1 = 1;
            } else if (ctr2 == 0) {
                cand2 = x;
                ctr2 = 1;
            } else {
                ctr1--;
                ctr2--;
            }
        }

        ctr1 = ctr2 = 0;
        for (int y : nums) {
            if (y == cand1) ctr1++;
            else if (y == cand2) ctr2++;
        }

        vector<int> ans;
        if (ctr1 > n / 3) ans.push_back(cand1);
        if (ctr2 > n / 3) ans.push_back(cand2);
        
        return ans;
    }
};