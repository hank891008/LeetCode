class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> new_cells(8, 0);
        map<int, vector<int>>m;
        set<vector<int>>s;
        for(int i = 0; ; i++){
            for(int j = 1; j < 7; j++){
                if((cells[j - 1] ^ cells[j + 1]) == 0){
                    new_cells[j] = 1;
                }
                else{
                    new_cells[j] = 0;
                }
            }
            cells = new_cells;
            if(!s.count(cells)){
                m[i] = cells;
                s.insert(cells);
            }
            else{
                break;
            }
        }
        return m[(n - 1) % m.size()];
    }
};