class Solution {
public:
     int binary_search(vector<int>& arr,int l,int u)
     {
        while(l<=u)
        {
            int mid=(l+u)/2;
            if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == (arr.size()-1) || arr[mid] >                       arr[mid+1])) {
                return mid;
            }
            if(mid > 0 && arr[mid] < arr[mid-1])
            {
                u=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
         return -1;
    }
    int findPeakElement(vector<int>& nums) {
          int n=nums.size();
        return binary_search(nums,0,n-1);
    }
};