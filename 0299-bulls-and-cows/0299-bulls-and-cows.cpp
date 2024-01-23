class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                a++;
                secret[i] = 'X';
                guess[i] = 'O';
            }
        }
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == 'X'){
                continue;
            }
            auto it = find(guess.begin(), guess.end(), secret[i]);
            if(it != guess.end()){
                b++;
                *it = 'O';
            }
        }
        string ans;
        ans += to_string(a) + 'A' + to_string(b) + 'B';
        return ans;
    }
};