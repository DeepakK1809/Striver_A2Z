class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int I=1 ;I<=n;I++){
            if(n%I==0){
                int i=nums[I-1];
                ans+=(i*i);
            }
        }
        return ans;
    }
};