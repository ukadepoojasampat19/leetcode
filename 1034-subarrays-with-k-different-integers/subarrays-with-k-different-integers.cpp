class Solution {
public:
      int atmost(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l = 0 ,cnt =0;
        for(int i = 0 ; i < nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]<=0){
                    mp.erase(nums[l]);
                }
                
                l++;
            }
            
            cnt+=i-l+1;
            
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       /* int right=1,left=0,ct=0;
        unordered_map<int,int> temp;
        while(right <= nums.size())
        {
            temp[nums[right-1]]++;
            if(right >= k)
            {
                if(temp.size() == k)
                {
                    ct++;
                    temp[nums[left]]--;
                    left++;
                    temp[nums[right-1]]--;
                    right--;
             
            }
            right++;
        }
        return ct;*/
        //brute force
       /* int ct=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int> temp;
            for(int j=i;j<nums.size();j++)
            {
                temp[nums[j]]++;
                if(temp.size() == k)
                {
                    ct++;
                }
            }
        }
        return ct;*/
         return atmost(nums,k) - atmost(nums,k-1);
    }
};