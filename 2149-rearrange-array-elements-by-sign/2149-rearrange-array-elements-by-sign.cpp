class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> R_array(nums.size());
        int pos=0;
        int neg=1;
        for(int i:nums){
            if(i>0){
                R_array[pos]=i;
                pos+=2;
            }else{
                R_array[neg]=i;
                neg+=2;
            }
        }     
        return R_array;
    }
};
