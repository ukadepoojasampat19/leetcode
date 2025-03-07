class Solution {
public:
     bool getPrimeNumber(int st, int ed, vector<int>& prime_no) {
        for (int i = st; i <= ed; i++) {
            if (i <= 1) continue; // Exclude numbers <= 1
            if (i == 2 || i == 3) { 
                prime_no.push_back(i); 
                continue; 
            }
            if ((i % 2) != 0) {
                bool isPrime = true;
                int temp = sqrt(i);
                for (int j = 2; j <= temp; j++) {
                    if ((i % j) == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) prime_no.push_back(i);
            }
        }
        return prime_no.size() >= 2;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime_no;
        int min_value = INT_MAX;
        map<int, vector<int>> mp; // Fixed map declaration

        if (getPrimeNumber(left, right, prime_no)) {
            for (int i = 0; i < prime_no.size() - 1; i++) {
                int a = prime_no[i];
                int b = prime_no[i + 1];
                int diff = b - a;
                min_value = min(min_value, diff);
                
                if (mp.find(diff) == mp.end()) {
                    mp[diff] = {a, b};
                } else {
                    int temp = mp[diff][0];
                    if (temp > a) {
                        mp[diff] = {a, b};
                    }
                }
            }
        } else {
            return { -1, -1 };
        }
        
        return mp[min_value];

        
    }
};