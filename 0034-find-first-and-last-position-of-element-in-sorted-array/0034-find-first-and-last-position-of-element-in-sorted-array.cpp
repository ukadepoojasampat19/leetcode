class Solution {
public:
   
    int find_bound(vector<int>& nums,int l,int u,int target,int index,bool first)
    {
       
         if(l<=u)
        {
            int mid=(l+u)/2;
            if( nums[mid] == target)
            {
                index=mid;
                if(first)
                {
                    return find_bound(nums,l,mid-1,target,index,first);
                }
                else
                {
                    return find_bound(nums,mid+1,u,target,index,first);
                }
                
               
            }
            else if(target < nums[mid])
            { 
                return find_bound(nums,l,mid-1,target,index,first);
            }
            else
            {
                return find_bound(nums,mid+1,u,target,index,first);
            }
        }
        return index;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
      
        int l=0;
        int u=n-1;
        int index=0;
        int left=find_bound(nums,l,u,target,-1,true);
        int right=find_bound(nums,l,u,target,-1,false);
        
        return {left,right};
        
       
        
    }
};