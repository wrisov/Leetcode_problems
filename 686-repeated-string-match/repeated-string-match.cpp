class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;

        // Keep repeating until length >= b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check current
        if (repeated.find(b) != string::npos)
            return count;

        // Check one extra repetition
        repeated += a;

        if (repeated.find(b) != string::npos)
            return count + 1;

        return -1;
    }
};