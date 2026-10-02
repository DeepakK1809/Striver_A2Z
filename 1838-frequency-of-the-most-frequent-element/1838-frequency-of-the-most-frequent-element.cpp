class Solution {
public:
    int maxFrequency(vector<int>& v, int k) {

        sort(v.begin(), v.end());

        long long sum = 0;
        int l = 0;
        int ans = 1;

        for (int r = 0; r < v.size(); r++) {

            sum += v[r];

            while ((long long)v[r] * (r - l + 1) - sum > k) {
                sum -= v[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};