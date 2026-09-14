class Solution {
public:
    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    void merge(std::vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        temp.reserve(high - low + 1);

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left++]);
        }
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;
        if (low >= high) return count;

        int mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};