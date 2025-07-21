class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        ans += s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt > 2){
                    continue;
                }
                else{
                    ans += s[i];
                }
            }
            else{
                ans += s[i];
                cnt = 1;
            
            }
        }
        return ans;
    }
};