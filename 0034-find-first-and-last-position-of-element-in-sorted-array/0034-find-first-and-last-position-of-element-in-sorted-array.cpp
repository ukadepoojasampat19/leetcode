class Solution {
public:
    int left_bound(vector<int>& nums,int l,int u,int target,int index)
    {
      
         if(l<=u)
        {
            int mid=(l+u)/2;
            if( nums[mid] == target)
            {
                index=mid;
                return left_bound(nums,l,mid-1,target,index);
               
            }
            else if(target < nums[mid])
            { 
                return left_bound(nums,l,mid-1,target,index);
            }
            else
            {
                return left_bound(nums,mid+1,u,target,index);
            }
        }
        return index;
    }
    int right_bound(vector<int>& nums,int l,int u,int target,int index)
    {
       
         if(l<=u)
        {
            int mid=(l+u)/2;
            if( nums[mid] == target)
            {
                index=mid;
                return right_bound(nums,mid+1,u,target,index);
               
            }
            else if(target < nums[mid])
            { 
                return right_bound(nums,l,mid-1,target,index);
            }
            else
            {
                return right_bound(nums,mid+1,u,target,index);
            }
        }
        return index;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> result;
        int l=0;
        int u=n-1;
        int index=0;
        int left=left_bound(nums,l,u,target,-1);
        int right=right_bound(nums,l,u,target,-1);
        result.push_back(left);
         result.push_back(right);
        return result;
        
       
        
    }
};