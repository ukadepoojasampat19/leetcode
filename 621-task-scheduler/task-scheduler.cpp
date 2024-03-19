class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char, int> taskCounts;
    
    // Count the frequency of each task
    for (char task : tasks)
        taskCounts[task]++;
    
    // Sort tasks by frequency
    vector<int> counts;
    for (auto& kv : taskCounts)
        counts.push_back(kv.second);
    sort(counts.begin(), counts.end(), greater<int>());
    
    int maxCount = counts[0]; // Get the maximum task count
    int idleTime = (maxCount - 1) * n; // Calculate idle time
    for (int i = 1; i < counts.size(); ++i) {
        idleTime -= min(maxCount - 1, counts[i]); // Deduct idle time by the minimum of (maxCount - 1) and task count
    }
    
    idleTime = max(0, idleTime); // Idle time cannot be negative
    return tasks.size() + idleTime; // Total intervals require
        
    }
};