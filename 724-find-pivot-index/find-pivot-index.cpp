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
       int total_sum =0,left_sum=0;
       

       for(auto &n : nums)
       {
          total_sum += n;
       }

       for(int i=0; i<nums.size();i++)
       {
          int right_sum = total_sum - left_sum - nums[i];

          if(left_sum == right_sum)
          {
            return i;
          }
          left_sum += nums[i];
       }
        return -1;
    }
};