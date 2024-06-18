class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        priority_queue<pair<int, int>> pq;
        for(int i=0;i<difficulty.size();i++)
        {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({prof,diff});
        }
        
        int total_profit = 0;
        int i=0;
        sort(worker.begin(),worker.end(),greater<int>());
        while(i < worker.size() && !pq.empty())
        {
            if(pq.top().second > worker[i])
            {
                pq.pop();
            }
            else
            {
                total_profit += pq.top().first;
                i++;
            }
        }
        return total_profit;
    }
};