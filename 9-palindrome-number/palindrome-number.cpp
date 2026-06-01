class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        cout <<num;
        int n = num.length();
        int l=0;
        int r = n-1;

        while(l < r){
           if(num[l] != num[r]) return false;
           l++;
           r--;

        }
        return true;
    }
};