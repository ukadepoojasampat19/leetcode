class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       /* int l=0,r=0;
        int ct_z=0;
        int result=0;
        int max_num=0;
        while(l < r)
        {
            if(nums[r] == 1)
            {
                result++;
            }
            else
            {
                if(ct_z < k)
                {
                    ct_z++;
                    result++;
                }
                else
                {
                    max_num = max(result,max_num);
                    if(nums[l] != 1)
                    {
                        ct_z--;
                        result--;
                        

                    }
                    l++;
                }
            }
            r++;
        }
        return max_num;*/
        int l = 0, r = 0;
        int ct_z = 0;
        int max_num = 0;

        while (r < nums.size()) {
            if (nums[r] == 0) {
                ct_z++;
            }

            while (ct_z > k) {
                if (nums[l] == 0) {
                    ct_z--;
                }
                l++;
            }

            max_num = max(max_num, r - l + 1);
            r++;
        }

        return max_num;
    }
};