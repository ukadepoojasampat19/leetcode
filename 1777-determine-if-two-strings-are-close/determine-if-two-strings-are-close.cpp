class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // If the lengths are different, they cannot be close
    if (word1.length() != word2.length()) {
        return false;
    }
    
    // Maps to store character frequencies
    unordered_map<char, int> freq1, freq2;
    // Sets to store unique characters
    unordered_set<char> set1, set2;
    
    // Fill the maps and sets
    for (char c : word1) {
        freq1[c]++;
        set1.insert(c);
    }
    for (char c : word2) {
        freq2[c]++;
        set2.insert(c);
    }
    
    // If the sets of unique characters are not the same, return false
    if (set1 != set2) {
        return false;
    }
    
    // Vectors to store the frequencies
    vector<int> vec1, vec2;
    
    for (const auto &p : freq1) {
        vec1.push_back(p.second);
    }
    for (const auto &p : freq2) {
        vec2.push_back(p.second);
    }
    
    // Sort the frequency vectors
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    
    // If the sorted frequency vectors are not the same, return false
    return vec1 == vec2;
        
    }
};