class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        typedef pair<int,int> P;
       int l=0; 
       int r=0;
       int n= nums.size();
       int max_value =0;
      priority_queue<P,vector<P>> max_q;
      priority_queue<P,vector<P>,greater<P>> min_q;
       
      // sort(nums.begin(),nums.end());
       while(r<n)
       {
           max_q.push({nums[r],r});
           min_q.push({nums[r],r});
           while(max_q.top().first - min_q.top().first > limit)
           {
               l = min(max_q.top().second,min_q.top().second) + 1;
                while(max_q.top().second < l)
                {
                    max_q.pop();
                }
                while(min_q.top().second < l)
                {
                    min_q.pop();
                }
           }
           max_value = max(max_value,r-l+1);
           r++;

       }
        return max_value;
       
    }
};