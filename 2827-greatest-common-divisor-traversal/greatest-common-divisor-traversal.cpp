
class DSU {
public:
    vector<int> dsu;
    vector<int> size;

    DSU(int N) : dsu(N + 1), size(N + 1, 1) {
        for (int i = 0; i <= N; i++) {
            dsu[i] = i;
        }
    }

    int find(int x) {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }

    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) {
            return;
        }
        if (size[fx] > size[fy]) {
            swap(fx, fy);
        }
        dsu[fx] = fy;
        size[fy] += size[fx];
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int MAX = 100000;
        const int N = nums.size();
        vector<bool> has(MAX + 1, false);
        for (int x : nums) {
            has[x] = true;
        }

        // Edge cases
        if (N == 1) {
            return true;
        }
        if (has[1]) {
            return false;
        }

        // General solution
        vector<int> sieve(MAX + 1, 0);
        for (int d = 2; d <= MAX; d++) {
            if (sieve[d] == 0) {
                for (int v = d; v <= MAX; v += d) {
                    sieve[v] = d;
                }
            }
        }

        DSU unionFind(2 * MAX + 1);
        for (int x : nums) {
            int val = x;
            while (val > 1) {
                int prime = sieve[val];
                int root = prime + MAX;
                if (unionFind.find(root) != unionFind.find(x)) {
                    unionFind.merge(root, x);
                }
                while (val % prime == 0) {
                    val /= prime;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= MAX; i++) {
            if (has[i] && unionFind.find(i) == i) {
                cnt++;
            }
        }
        return cnt == 1;
    }
     
    
};