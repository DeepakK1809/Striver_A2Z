class Solution {
public:
    vector<vector<int>> ans;
    void Solve(vector<int> v,int i,vector<int>temp){
        if(i>=v.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(v[i]);
        Solve(v,i+1,temp);
        temp.pop_back();
        Solve(v,i+1,temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<int> temp;
        Solve(nums,0,{});
        return ans;
    }
};