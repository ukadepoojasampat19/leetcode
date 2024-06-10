class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      /*  int right_sum =0;
        int n = nums.size();
        int idx=0,left_sum=0;

        //right sum calculate keli
        for(int i=0;i<n;i++)
        {
            right_sum += nums[i];
        }

        while(idx < n)
        {
            right_sum -= nums[idx];
            if(left_sum == right_sum)
            {
                return idx;
            }
            else
            {
                left_sum += nums[idx];
                
                idx++;
            }

        }

        return -1;*/
         int total_sum = 0, left_sum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            total_sum += num;
        }

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Right sum for index i can be derived from total_sum and left_sum
            int right_sum = total_sum - left_sum - nums[i];

            // Check if left sum equals right sum
            if (left_sum == right_sum) {
                return i;
            }

            // Update left sum for the next index
            left_sum += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
        

    }
};