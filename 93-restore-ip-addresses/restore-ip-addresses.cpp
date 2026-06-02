class Solution {
public:
    vector<string> ans;

    bool isValid(string part) {

        if(part.size() > 1 && part[0] == '0')
            return false;

        int num = stoi(part);

        return num >= 0 && num <= 255;
    }

    void backtrack(string &s,
                   int idx,
                   int parts,
                   string curr) {

        if(parts == 4) {

            if(idx == s.size()) {
                curr.pop_back();      // remove last '.'
                ans.push_back(curr);
            }

            return;
        }

        for(int len = 1; len <= 3; len++) {

            if(idx + len > s.size())
                break;

            string part = s.substr(idx, len);

            if(isValid(part)) {

                backtrack(
                    s,
                    idx + len,
                    parts + 1,
                    curr + part + "."
                );
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {

        backtrack(s, 0, 0, "");

        return ans;
    }
};