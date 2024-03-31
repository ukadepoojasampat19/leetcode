class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

     /*   long long count=0;
        int right=0,left=0;
        int mx=INT_MIN;
        unordered_map<int,int> temp;
        while(right < nums.size())
        {
            temp[nums[right]]++;
            if(nums[right] >= maxK)
            {
                mx=max(mx,nums[right]);
                if(nums[left] < minK)
                {
                    while(nums[left] <= minK)
                    {
                       
                        left++;
                    }

                }
                else if(nums[left] == minK)
                {
                    count++;
                    left=nums[left];
                }
                
            }
            else
            {
                mx=max(mx,nums[right]);
                if(mx == maxK)
                {
                   count++;
                }
            }
           
            right++;
        }
        if(temp.size() == 1)
        {
            count+=6;
        }
        return count;*/
         long long ans=0;
        int maxi=-1, mini=-1;
        int s=nums.size();
        for(int r=0, l=0; r<s; r++){
            int x=nums[r];
            if (x<minK ||x>maxK){// x exceeds the bound
                l=r+1; // move l to r+1
                continue;
            }
            if (x==maxK) maxi=r; // position for maxK
            if (x==minK) mini=r; // position for minK
            ans+=max((min(maxi, mini)-l+1),0);
        }
        return ans;
        
    }
};