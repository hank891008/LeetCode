class Solution {
private:
    vector<string>ans;
    void valid(vector<bool> b){
        int h = 8 * b[0] + 4 * b[1] + 2 * b[2] + b[3];
        int m = 32 * b[4] + 16 * b[5] + 8 * b[6] + 4 * b[7] + 2 * b[8] + b[9];
        if(h <= 11 && h >= 0 && m <= 59 && m >= 0){
            string tmp = to_string(h) + ':';
            if(m < 10){
                tmp += "0";
            }
            tmp += to_string(m);
            ans.emplace_back(tmp);
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<bool>b(10);
        for(int i = 0; i < turnedOn; i++){
            b[9 - i] = 1;
        }
        do{
            valid(b);
        }while(next_permutation(b.begin(), b.end()));
        return ans;
    }
};