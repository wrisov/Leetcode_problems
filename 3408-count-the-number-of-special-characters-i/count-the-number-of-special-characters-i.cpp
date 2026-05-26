class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> mp;
        unordered_set<char> c;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            mp[ch]++;
            if(islower(ch)){
                char u = (char)toupper(ch);
                if(mp.find(u)!=mp.end()){
                    c.insert(ch);
                }
            } else {
                char l =(char)tolower(ch);
                if(mp.find(l)!=mp.end()){
                    c.insert(l);
                }
            }
        }
        return c.size();
    }
};