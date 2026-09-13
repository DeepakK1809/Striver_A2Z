class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long MaxP=nums[0];//6
        long long MinSoFar=nums[0]; //2
        long long MaxSoFar=nums[0]; //6
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(MinSoFar,MaxSoFar);
            }
            MaxSoFar=max((long long )nums[i],MaxSoFar*nums[i]);
            MinSoFar=min((long long )nums[i],MinSoFar*nums[i]);
            MaxP=max(MaxP,MaxSoFar);
        }
        return MaxP;
    }
};