class Solution {
public:
    int calPoints(vector<string>& operations) {
        int record[1005];
        int idx = 0;
        for(auto op: operations){
            if(isdigit(op[0]) || op[0] == '-'){
                record[idx++] = stoi(op);
            }
            else if(op == "+"){
                record[idx++] = record[idx - 1] + record[idx - 2];
            }
            else if(op == "D"){
                record[idx++] = 2 * record[idx - 1];
            }
            else{
                idx--;
                
            }
        }
        return accumulate(record, record + idx, 0);
    }
};