class Solution {
public:
    typedef long long li;
    long long wonderfulSubstrings(string word) {
      /*  vector<long long> count(1024, 0); // 2^10 to store XOR values
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (char ch : word) {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor];
            for (int i = 0; i < 10; i++) {
                result += count[prefixXor ^ (1 << i)];
            }
            count[prefixXor]++;
        }

        return result;*/
        unordered_map<li, li> mp;

        mp[0]=1; //
        int cum_xor =0;
        li result = 0;
        for(char &ch : word)
        {
            int shift=ch -'a';
            //1 << shift ->binary rep of ch

            cum_xor ^= (1 << shift);
            result += mp[cum_xor];
            for(char ch1='a';ch1 <= 'j';ch1++)
            {
                shift=ch1 - 'a';
                li check_xor =cum_xor ^ (1 << shift);
                result += mp[check_xor];
            }
            mp[cum_xor]++;
        }
    return result;
    }
};