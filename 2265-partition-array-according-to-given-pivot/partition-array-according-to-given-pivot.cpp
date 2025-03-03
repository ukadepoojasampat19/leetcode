class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       list<int> less;
       list<int> equal;
       list<int> greater;
        vector<int> res;

       for(auto& n: nums){
        if(n < pivot){
            less.push_back(n);
        }else if(n  > pivot){
            greater.push_back(n);
        }else{
            equal.push_back(n);
        }
       }
       less.insert(less.end(), equal.begin(), equal.end());
       less.insert(less.end(), greater.begin(), greater.end());
       for(auto& num : less){
            res.push_back(num);
       }
       return res;
    }
};