class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> result;
    unordered_map<int, int> mp;


      int n = nums.size();

      for(int j=0;j<n;j++){
          int num = target - nums[j];
          if(mp.find(num) != mp.end()){
             result = { mp[num] , j};
          }
          mp[nums[j]] = j;

      }
      return result;
    }
};