class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node memo[20][11][11][3];
    bool vis[20][11][11][3];

    Node dfs(int pos, int a, int b, int len, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][a][b][len]) {
            return memo[pos][a][b][len];
        }

        int limit = tight ? s[pos] - '0' : 9;

        Node res{0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (len == 0 && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, 0, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else if (len == 0) {
                Node nxt = dfs(pos + 1, d, 10, 1, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else if (len == 1) {
                Node nxt = dfs(pos + 1, a, d, 2, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                int add = 0;

                if ((b > a && b > d) ||
                    (b < a && b < d))
                    add = 1;

                Node nxt = dfs(pos + 1, b, d, 2, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + nxt.cnt * add;
            }
        }

        if (!tight) {
            vis[pos][a][b][len] = true;
            memo[pos][a][b][len] = res;
        }

        return res;
    }

    long long solve(long long N) {
        if (N < 0) return 0;

        s = to_string(N);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};