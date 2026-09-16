class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low=1;
        int minBnanaToEat=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long time=0;
            for(int i=0;i<piles.size();i++){
                time+=(piles[i] +mid - 1) / mid;
            }
            if (time>h){
                low=mid+1;
            }
            else if(time<=h){
                minBnanaToEat=mid;
                high=mid-1;
            }
        }
        return minBnanaToEat;
        
    }
};