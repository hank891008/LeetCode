class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int empty_row = n;
        int prev_row = 0;
        int prev_column = 0;
        int ans = 0;
        int i = 0;
        while(i < reservedSeats.size()){
            if(reservedSeats[i][0] != prev_row){
                empty_row--;
                prev_column = 0;
            }
            int j = i;
            vector<int>row;
            row.emplace_back(0);
            while(j < reservedSeats.size() - 1 && reservedSeats[j][0] == reservedSeats[j + 1][0]){
                row.emplace_back(reservedSeats[j++][1]);
            }
            row.emplace_back(reservedSeats[j++][1]);
            row.emplace_back(11);
            for(int k = 0; k < row.size() - 1; k++){
                int flag = true;
                if(row[k] <= 1 && row[k + 1] >= 6){
                    ans++;
                    flag = false;
                }
                if(row[k] <= 5 && row[k + 1] >= 10){
                    ans++;
                    flag = false;
                }
                if(flag && row[k] <= 3 && row[k + 1] >= 8){
                    ans++;
                }
            }
            prev_row = reservedSeats[i][0];
            prev_column = reservedSeats[i][1];
            i = j;
        }
        return ans + 2 * empty_row;
        
    }
};