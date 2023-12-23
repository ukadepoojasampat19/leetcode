class Solution {
public:
    int binary_search(vector<int>& nums,int l,int u,int target)
    {
        while(l<=u)
        {
            int mid=(l+u)/2;
            if(nums[mid] ==  target)
            {
                return mid;
            }
            
            //left sorted arr check condition 
            if(nums[l] <= nums[mid])
            {
                if(nums[l]<= target && target <= nums[mid])
                {
                    u=mid-1;
                }
                else
                {
                    l=mid+ 1;
                }
            }
            else   //check condition fro right sorted array
            {
                if(nums[mid]< target && target<= nums[u])
                {
                    l=mid+1;
                }
                else
                {
                    u=mid-1;
                }
                
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int n=nums.size();
       
       
        return binary_search(nums,0,n-1,target);
        
    }
};