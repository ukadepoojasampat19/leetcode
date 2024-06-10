class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum =0;
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

        return -1;
        

    }
};