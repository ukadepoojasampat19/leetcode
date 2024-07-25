class Solution {
public:
    void merge(vector<int>& nums, int st, int ed, int mid) {
        int n1 = mid - st + 1;
        int n2 = ed - mid;
        vector<int> left_arr(n1);
        vector<int> right_arr(n2);
        
        for (int i = 0; i < n1; ++i) {
            left_arr[i] = nums[st + i];
        }
        for (int i = 0; i < n2; ++i) {
            right_arr[i] = nums[mid + 1 + i];
        }
        
        int i = 0, j = 0, k = st;
        while (i < n1 && j < n2) {
            if (left_arr[i] <= right_arr[j]) {
                nums[k] = left_arr[i];
                ++i;
            } else {
                nums[k] = right_arr[j];
                ++j;
            }
            ++k;
        }
        
        while (i < n1) {
            nums[k] = left_arr[i];
            ++i;
            ++k;
        }
        while (j < n2) {
            nums[k] = right_arr[j];
            ++j;
            ++k;
        }
    }

    void merge_sort(vector<int>& nums, int st, int ed) {
        if (st < ed) {
            int mid = st + (ed - st) / 2; // Avoid overflow
            merge_sort(nums, st, mid);
            merge_sort(nums, mid + 1, ed);
            merge(nums, st, ed, mid);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int ed = nums.size() - 1;
        merge_sort(nums, l, ed);
        return nums;
    }
};
