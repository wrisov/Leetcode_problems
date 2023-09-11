class Solution {
public:
    bool isMatch(string s, string p) {
         int l1 = s.length();
    int l2 = p.length();

    bool dp[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            //base cases

            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                if (j == 1)
                {
                    dp[i][j] = false;
                }
                else if (p[j - 1] != '*')
                {
                    dp[i][j] = false;
                }
                else
                {
                    dp[i][j] = dp[i][j - 2];
                }
            }

            else if (j == 0)
            {
                dp[i][j] = false;
            }

            //main body

            else
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[l1][l2];

    }
};