class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a;
        map<int,int> occur;
        for(int i: nums)
        {
             occur[i]++;
        }
       for(const auto &n: occur)
       {
           if(n.second == 1)
           {
               a=n.first;
           }
       }
        return a;
}
    
};