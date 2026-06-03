class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        auto solveOneDirection =
            [&](vector<int>& startA,
                vector<int>& durA,
                vector<int>& startB,
                vector<int>& durB) {

            int N = startA.size();
            int M = startB.size();

            vector<pair<long long,long long>> rides;

            for(int i=0;i<M;i++)
                rides.push_back({startB[i], durB[i]});

            sort(rides.begin(), rides.end());

            vector<long long> starts(M);
            vector<long long> prefMinDur(M);
            vector<long long> suffMinFinish(M);

            for(int i=0;i<M;i++) {
                starts[i] = rides[i].first;

                if(i==0)
                    prefMinDur[i] = rides[i].second;
                else
                    prefMinDur[i] =
                        min(prefMinDur[i-1],
                            rides[i].second);
            }

            for(int i=M-1;i>=0;i--) {

                long long val =
                    rides[i].first +
                    rides[i].second;

                if(i==M-1)
                    suffMinFinish[i] = val;
                else
                    suffMinFinish[i] =
                        min(suffMinFinish[i+1], val);
            }

            long long best = LLONG_MAX;

            for(int i=0;i<N;i++) {

                long long finishFirst =
                    (long long)startA[i] +
                    durA[i];

                int pos =
                    upper_bound(
                        starts.begin(),
                        starts.end(),
                        finishFirst
                    ) - starts.begin();

                if(pos > 0)
                    best = min(
                        best,
                        finishFirst +
                        prefMinDur[pos-1]
                    );

                if(pos < M)
                    best = min(
                        best,
                        suffMinFinish[pos]
                    );
            }

            return best;
        };

        ans = min(
            solveOneDirection(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ),
            solveOneDirection(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            )
        );

        return ans;
    }
};