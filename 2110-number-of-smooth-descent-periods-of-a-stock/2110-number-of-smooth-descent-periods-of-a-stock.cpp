class Solution {
public:
    long long getDescentPeriods(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        long long ans = 0;
        int start = 0;
        int end = 0;
        int precd = 0;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] == nums[precd] - 1) {
                end = i;
            }
            else {
                long long len = end - start + 1;
                ans += len * (len + 1) / 2;

                start = i;
                end = i;
            }

            precd = i;
        }

        long long len = end - start + 1;
        ans += len * (len + 1) / 2;

        return ans;
    }
};