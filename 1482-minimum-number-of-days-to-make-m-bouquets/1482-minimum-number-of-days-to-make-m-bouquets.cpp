class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            int bouquets = 0;
            int ctr = 0;

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    ctr++;
                    if (ctr == k) {
                        bouquets++;
                        ctr = 0;
                    }
                } else {
                    ctr = 0;
                }
            }

            if (bouquets >= m) {
                ans = mid;
                h = mid - 1;  
            } else {
                l = mid + 1;   
            }
        }
        return ans;
    }
};
