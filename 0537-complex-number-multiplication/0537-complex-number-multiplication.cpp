class Solution {
public:
    pair<int, int> solve(string num){
        string tmp_real, tmp_cmx;
        int i = 0;
        if(num[i] == '-'){
            tmp_real += '-';
            i++;
        }
        while(true){
            if(isdigit(num[i])){
                tmp_real += num[i++];
            }
            else{
                i++;
                break;
            }
        }
        if(num[i] == '-'){
            tmp_cmx += '-';
            i++;
        }
        while(i < num.size()){
            if(isdigit(num[i])){
                tmp_cmx += num[i++];
            }
            else{
                i++;
                break;
            }
        }
        return {stoi(tmp_real), stoi(tmp_cmx)};
        
    }
    string complexNumberMultiply(string num1, string num2) {
        auto n1 = solve(num1), n2 = solve(num2);
        int a = n1.first * n2.first - n1.second * n2.second;
        int b = n1.first * n2.second + n2.first * n1.second;
        string ans;
        ans += to_string(a);
        ans += '+';
        ans += to_string(b);
        ans += 'i';
        return ans;
    }
};