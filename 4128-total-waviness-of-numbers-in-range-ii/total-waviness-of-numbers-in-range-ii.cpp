class Solution {
public:
    
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int prev2, int prev1,
             bool tight, bool started) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][prev2 + 1][prev1 + 1][tight][started])
            return dp[pos][prev2 + 1][prev1 + 1][tight][started];

        vis[pos][prev2 + 1][prev1 + 1][tight][started] = true;

        Node res = {0, 0};

        int limit = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (!started && d == 0) {

                Node nxt = dfs(
                    pos + 1,
                    -1,
                    -1,
                    ntight,
                    false
                );

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {

                int add = 0;

                if (started && prev2 != -1) {

                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                int nprev2 = started ? prev1 : -1;
                int nprev1 = d;

                Node nxt = dfs(
                    pos + 1,
                    nprev2,
                    nprev1,
                    ntight,
                    true
                );

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        return dp[pos][prev2 + 1][prev1 + 1][tight][started] = res;
    }

    long long solve(long long x) {

        if (x <= 0)
            return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        Node ans = dfs(0, -1, -1, true, false);

        return ans.wav;
    }

    long long totalWaviness(long long num1, long long num2) {

        return solve(num2) - solve(num1 - 1);
    }
};