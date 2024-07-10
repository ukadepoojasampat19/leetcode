class Solution {
public:
    int minOperations(vector<string>& logs) {
        string parent_folder = "../";
        string same_folder = "./";
        int result = 0;
        int n = logs.size();
        for(int i=0;i<n; i++)
        {
            if(logs[i] == parent_folder && result >0)
            {
                result--;
            }
            else if(logs[i] != parent_folder && logs[i] != same_folder)
            {
                result++;
            }
        }
        if(result < 0) return 0;
        return result;
    }
};