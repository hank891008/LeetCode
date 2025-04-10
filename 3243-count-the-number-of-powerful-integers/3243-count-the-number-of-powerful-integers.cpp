class Solution {
public:
    long long solve(string x, string s, int limit){
        if(x.size() < s.size()){
            return 0;
        }
        else if(x.size() == s.size()){
            return x >= s ? 1 : 0;
        }
        int len = x.size() - s.size();
        long long cnt = 0;
        for(int i = 0; i < len; i++){
            if((x[i] - '0') > limit){
                cnt += (long long)pow(limit + 1, len - i);
                return cnt;
            }
            else{
                cnt += (x[i] - '0') * (long long)pow(limit + 1, len - 1 - i);
            }
        }
        return cnt + (x.substr(len, s.size()) >= s);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return solve(to_string(finish), s, limit) - solve(to_string(start - 1), s, limit);
    }
};