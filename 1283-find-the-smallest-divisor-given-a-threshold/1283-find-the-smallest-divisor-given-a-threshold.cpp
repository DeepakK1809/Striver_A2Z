class Solution {
public:
    int CSum(vector<int>& a,int d){
        int sum=0;
        for(int i:a){
            sum+=(i+d-1)/d;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
       
        int high =*max_element(nums.begin(),nums.end());
        while(low<high){
            int mid=low+(high-low)/2;
            int sum=CSum(nums,mid);
            if (sum<=threshold){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};