class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long acc = 0;
        for(auto c: chalk){
            acc += c;
            if(acc > k){
                break;
            }
        }
        k %= acc;
        for(int i = 0; i < chalk.size(); i++){
            if(k - chalk[i] < 0){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};