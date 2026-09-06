class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ctr = 0;
        int start = 0;

        int bestStart = 0;
        int bestEnd = 0;
        int M_Sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            ctr += nums[i];

            if (ctr > M_Sum) {
                M_Sum = ctr;
                bestStart = start;
                bestEnd = i;
            }

            if (ctr < 0) {
                ctr = 0;
                start = i + 1;
            }
        }
        
        return M_Sum;
    }
};