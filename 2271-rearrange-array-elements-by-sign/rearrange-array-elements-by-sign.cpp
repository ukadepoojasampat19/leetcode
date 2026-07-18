class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> plusNo;
        vector<int> minusNo;
        int n = plusNo.size() + minusNo.size();
        vector<int> res(n);

        for(int num : nums){
            if(num < 0){
                minusNo.push_back(num);
            }else{
                plusNo.push_back(num);
            }
        }
        for(int i=0;i<plusNo.size();i++){
            res.push_back(plusNo[i]);
            res.push_back(minusNo[i]);
        }
       
       
        return res;
    }
};