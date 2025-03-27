class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mpf;
        unordered_map<int,int> mps;

        int  n = nums.size();

        for(auto &num : nums){
            mps[num]++;
        }


        for(int i=0;i<n;i++){
            int num = nums[i];

            mps[num]--;
            mpf[num]++;

            if(mpf[num] > (i+1)/2 && mps[num] > (n-i-1)/2){
                    return i;
            }

        }
        return -1;
    }
};