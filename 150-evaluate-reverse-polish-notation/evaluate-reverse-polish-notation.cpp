class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         std::stack<int> st;
        
        if(tokens.size() == 1) return stoi(tokens[0]);
        
        std::unordered_set<std::string> op({"+", "-", "*", "/"});
        
        for(int i = 0; i < tokens.size(); i++){
            if(op.count(tokens[i]) != 0){
                // found operation
                auto f = st.top(); st.pop();
                auto s = st.top(); st.pop();
                int ans = 0;
                if(tokens[i] == "+") ans = f + s;
                else if(tokens[i] == "-") ans = s - f;
                else if(tokens[i] == "*") ans = f * s;
                else if(tokens[i] == "/") ans = s / f;
                
                st.push(ans);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();

    }
};