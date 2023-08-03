class Solution {
public:
    bool isValid(string s) {
        stack<int>g;
        for(int i=0;i<s.length();i++){
            if(!g.empty()&&s[i]==')'&&g.top()=='(')
                g.pop();
            else if(!g.empty()&&s[i]=='}'&&g.top()=='{')
                g.pop();
            else if(!g.empty()&&s[i]==']'&&g.top()=='[')
                g.pop();
            else
                g.push(s[i]);
        }
        return g.empty();   
    }
};