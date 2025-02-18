class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        stack<char> s;
        for(int i = 0; i <= pattern.size(); i++){
            s.emplace(i + 1);
            if(i == pattern.size() || pattern[i] == 'I'){
                while(!s.empty()){
                    ans += char(s.top() + '0');
                    s.pop();
                }
            }
        }
        return ans;
    }
};