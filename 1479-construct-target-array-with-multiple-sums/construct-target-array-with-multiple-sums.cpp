#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total = accumulate(target.begin(), target.end(), 0L);
        
        priority_queue<int> pq(target.begin(), target.end());

        while (true) {
            int maxVal = pq.top();
            pq.pop();

            long rest = total - maxVal;

            // Base cases
            if (maxVal == 1 || rest == 1) return true;

            // Invalid cases
            if (rest == 0 || maxVal < rest) return false;

            int prev = maxVal % rest;

            if (prev == 0) return false;

            pq.push(prev);
            total = rest + prev;
        }
    }
};