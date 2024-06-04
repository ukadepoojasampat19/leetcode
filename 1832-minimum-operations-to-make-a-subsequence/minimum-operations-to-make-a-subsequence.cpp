class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
      unordered_map<int,int> mp;
      vector<int> stack;

      for(auto& t: target)
      {
        mp[t]=mp.size();
      }

      for(auto& n: arr)
      {
        auto it= mp.find(n);
        if(it != end(mp))
        {
            if(stack.empty() || stack.back() < it->second)
            {
                stack.push_back(it->second);
            }
            else
            {
                *lower_bound(begin(stack),end(stack), it->second) = it->second;
            }
        }

      }
      return target.size() - stack.size();
        
    }
};