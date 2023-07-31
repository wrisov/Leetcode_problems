class Solution {
public:
    // function to find the length of the words in the temp vector used to storing answer of every row
int findLen(vector<string> s) {
    int cnt = 0;
    for(auto it: s) {
        cnt += it.length();
    }
    return cnt;
}

// function used to make the string -> more than 1 string in 1 row
string makeString(vector<string> s, int div, int rem) {
    string news = "";
    for(int i = 0; i < s.size(); i++) {
        news += s[i];
        if(i != s.size() - 1) {
            for(int j = 0; j < div; j++) news += " ";
            if(rem > 0) {
                news += " ";
                rem--;
            }
        }
    }
    return news;
}

// function used to make the string -> 1 string in 1 row
string makeStringOne(vector<string> temp, int maxWidth) {
    string s = "";
    for(int i = 0; i < temp.size(); i++) {
        s += temp[i];
        if(i != temp.size() - 1) s += " ";
    }
    int left = maxWidth - s.length();
    while(left--) s += " ";
    return s;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> ans;
    vector<string> temp;
    int left = maxWidth;
    bool isFirst = true;
    for(int i = 0; i < n; i++) {
        // we're checking the length of every word, if the length of the word plus the one space needed before it(if it's not the first word) is less than equal to the length left, then we add it else we add it to the next row.
        int wordLen = words[i].length();
        if(isFirst && wordLen <= left) {
            temp.push_back(words[i]);
            left -= wordLen;
            isFirst = false;
        } else if(!isFirst && wordLen + 1 <= left) {
            temp.push_back(words[i]);
            left -= (wordLen + 1);
        } else {
            string s = "";
            int totalLen = findLen(temp);
            int spacesLeft = maxWidth - totalLen;
            int wordCount = temp.size();
            // if there is one word in the vector we add it specially as the spaces would be different than the ones with more than 1 word in the vector.
            if(wordCount == 1) {
                s = makeStringOne(temp, maxWidth); 
            } else {
                int div = 0, rem = 0;
                div = spacesLeft / (wordCount - 1);
                if(spacesLeft % (wordCount-1) != 0)
                rem = spacesLeft % (wordCount-1);
                s = makeString(temp, div, rem);
            }
            ans.push_back(s); 
            temp.clear();
            left = maxWidth;
            isFirst = true;
            i--;
        }
    }
    if(temp.size() > 0) {
        string s = "";
        s = makeStringOne(temp, maxWidth);
        ans.push_back(s);
    }
    return ans;
}
};