class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<long long,long long>> water(m);
        for (int i = 0; i < m; i++) {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(water.begin(), water.end());

        vector<long long> waterStarts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinFinish(m);

        for (int i = 0; i < m; i++) {
            waterStarts[i] = water[i].first;

            if (i == 0)
                prefMinDur[i] = water[i].second;
            else
                prefMinDur[i] =
                    min(prefMinDur[i - 1], water[i].second);
        }

        for (int i = m - 1; i >= 0; i--) {
            long long val = water[i].first + water[i].second;

            if (i == m - 1)
                suffMinFinish[i] = val;
            else
                suffMinFinish[i] =
                    min(suffMinFinish[i + 1], val);
        }

        long long ans = LLONG_MAX;

        // land -> water
        for (int i = 0; i < n; i++) {

            long long A =
                (long long)landStartTime[i] + landDuration[i];

            int pos =
                upper_bound(waterStarts.begin(),
                            waterStarts.end(),
                            A)
                - waterStarts.begin();

            if (pos > 0) {
                ans = min(ans,
                          A + prefMinDur[pos - 1]);
            }

            if (pos < m) {
                ans = min(ans,
                          suffMinFinish[pos]);
            }
        }

        // preprocess land similarly
        vector<pair<long long,long long>> land(n);

        for (int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        sort(land.begin(), land.end());

        vector<long long> landStarts(n);
        vector<long long> prefMinDurLand(n);
        vector<long long> suffMinFinishLand(n);

        for (int i = 0; i < n; i++) {
            landStarts[i] = land[i].first;

            if (i == 0)
                prefMinDurLand[i] = land[i].second;
            else
                prefMinDurLand[i] =
                    min(prefMinDurLand[i - 1],
                        land[i].second);
        }

        for (int i = n - 1; i >= 0; i--) {
            long long val = land[i].first + land[i].second;

            if (i == n - 1)
                suffMinFinishLand[i] = val;
            else
                suffMinFinishLand[i] =
                    min(suffMinFinishLand[i + 1],
                        val);
        }

        // water -> land
        for (int i = 0; i < m; i++) {

            long long B =
                (long long)waterStartTime[i] + waterDuration[i];

            int pos =
                upper_bound(landStarts.begin(),
                            landStarts.end(),
                            B)
                - landStarts.begin();

            if (pos > 0) {
                ans = min(ans,
                          B + prefMinDurLand[pos - 1]);
            }

            if (pos < n) {
                ans = min(ans,
                          suffMinFinishLand[pos]);
            }
        }

        return ans;
    }
};