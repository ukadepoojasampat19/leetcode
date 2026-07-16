class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidates = 0;
        int ct =0;

        for(int num : nums){

            if(ct == 0){
                candidates = num;
            }
            if(num == candidates){
                ct++;
            }else{
                ct--;
            }
        }
        return candidates;
    }
};