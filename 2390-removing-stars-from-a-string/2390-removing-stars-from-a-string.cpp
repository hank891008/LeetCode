class Solution {
public:
    string removeStars(string s) {
        stack<char> Stack;
        for(auto ch: s){
            if(ch == '*'){
                Stack.pop();
            }
            else{
                Stack.emplace(ch);
            }
        }
        string ans;
        while(!Stack.empty()){
            ans += Stack.top(); Stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};