class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        shifts.back() %= 26;
        for(int i = (int)shifts.size() - 2; i >= 0; i--){
            shifts[i] = (shifts[i] % 26 + shifts[i + 1] % 26) % 26;
        }
        for(int i = 0; i < s.size(); i++){
            s[i] += shifts[i];
            while(!isalpha(s[i])){
                s[i] -= 26;
            }
        }
        return s;
    }
};