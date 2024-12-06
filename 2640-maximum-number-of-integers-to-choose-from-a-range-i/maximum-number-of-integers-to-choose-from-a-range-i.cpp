class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum =0;
        int count=0;
        unordered_set<int> mp(banned.begin(),banned.end());

        for(int i=1;i<=n;i++)
        {
            if(mp.count(i)) continue;
            sum += i;
            if(sum > maxSum) break;
            count++;
        }
        return count;
    }
};