class Solution {
public:
    int Sum(int i){
        string s=to_string(i);
        int sum=0;
        for(char c:s){
            sum+=c-'0';
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int ind=INT_MAX;
        bool DNE=true;
        for(int i=0;i<nums.size();i++){
            if(Sum(nums[i])==i){
                DNE=false;
                ind=min(i,ind);
            }
        }
        if(DNE){
            return -1;
        }else{
            return ind;
        }
    }
};