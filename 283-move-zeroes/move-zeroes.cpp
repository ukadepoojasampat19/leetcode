class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    /* int zero =0;
     for(int i=0;i< nums.size();i++)
     {
        if(nums[i] != 0)
        {
            nums[zero++] = nums[i];
        }
     }
     for(int i=zero;i<nums.size();i++)
     {
        nums[i] =0;
     }
*/
    int left=0;
    for(int right=0;right< nums.size(); right++)
    {
        if(nums[right] != 0)
        {
            swap(nums[left],nums[right]);
            left++;
        }
    }
        
    }
};