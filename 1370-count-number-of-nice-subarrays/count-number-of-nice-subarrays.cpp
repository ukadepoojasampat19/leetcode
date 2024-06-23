class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

      /*  unordered_map<int,int> mp;
        
        int odd_num =0;
        mp[odd_num]++;
        int n = nums.size();
        int result =0;
        for(int i=0;i<n;i++)
        {
            odd_num += (nums[i]%2);

            if(mp.count(odd_num -k))
            {
                result += mp[odd_num -k];
            }

            mp[odd_num]++;
        }
        return result;*/
        //si=liding window approach
        int prev_count=0;
        int odd_count=0;
        int l=0;
        int r=0,result =0;
        int n = nums.size();
        while(r<n)
        {
            if(nums[r]%2 != 0)
            {
                odd_count++;
                prev_count=0;
                
            }

            while(odd_count == k)
            {
                prev_count++;
                if(nums[l]%2 != 0)
                {
                    odd_count--;
                    
                }
                l++;
            }

            result += prev_count;
            r++;
        }
        return result;
    }
};