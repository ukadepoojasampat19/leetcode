class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(auto& n : strs)
        {
            string word = n;
            sort(word.begin(),word.end());
            mp[word].push_back(n);
        }

        for(auto& n: mp)
        {
            result.push_back(n.second);
        }

        return result;
    }
};