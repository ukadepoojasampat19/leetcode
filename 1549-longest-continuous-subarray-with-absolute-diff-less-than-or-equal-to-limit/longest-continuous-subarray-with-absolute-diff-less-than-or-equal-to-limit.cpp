class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
       /* typedef pair<int,int> P;
       int l=0; 
       int r=0;
       int n= nums.size();
       int max_value =0;
      priority_queue<P,vector<P>> max_q;
      priority_queue<P,vector<P>,greater<P>> min_q;
       //space 0(n+n);
      // sort(nums.begin(),nums.end());
       while(r<n)
       {
           max_q.push({nums[r],r});
           min_q.push({nums[r],r});
           while(max_q.top().first - min_q.top().first > limit)
           {
               l = min(max_q.top().second,min_q.top().second) + 1;
                while(max_q.top().second < l) // top sathi constant time 
                {
                    max_q.pop(); // log(n)
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
       // o(nlog(n));*/
       multiset<int> st;
       int n= nums.size();
       int i=0,j=0,mx_len=0;
       while(j<n)
       {
            st.insert(nums[j]);
            while(*st.rbegin() - *st.begin() > limit)
            {
                st.erase(st.find(nums[i]));
                i++;
            }
            mx_len = max(mx_len,j-i+1);
            j++;
       }
       return mx_len;
    }
};