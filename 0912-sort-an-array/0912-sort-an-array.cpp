class Solution {
public:
   void merge(int left, int right, int mid, vector<int>& arr) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> left_arr(n1), right_arr(n2);

        for (int i = 0; i < n1; i++) {
            left_arr[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            right_arr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (left_arr[i] <= right_arr[j]) {
                arr[k] = left_arr[i];
                i++;
            } else {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = left_arr[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
       // return arr;
    }

    void merge_sort(int l, int u, vector<int>& arr) {
        if (l < u) {
            int mid = l + (u - l) / 2;

            merge_sort(l, mid, arr);
            merge_sort(mid + 1, u, arr);

            merge(l, u, mid, arr);
        }
       // return arr;
    }

    vector<int> sortArray(vector<int>& nums) {
         int len_nums = nums.size();
        int l = 0;
        int u = len_nums - 1; // Adjust upper bound
        merge_sort(l, u, nums);
        return nums;
      
       
    }
};