class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, deletions = 0;

        for(char c : s) {
            if(c == 'b') {
                countB++;
            } else {
                deletions = std::min(deletions + 1, countB);
            }
        }

        return deletions;
    }
};
