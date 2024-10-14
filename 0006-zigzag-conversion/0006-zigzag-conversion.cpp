class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        char arr[1005][1005];
        memset(arr, 0, sizeof(arr));
        int i = 0, j = 0, k = 0;
        int cnt = 0;
        while(k < s.size()){
            arr[i++][j] = s[k++];
            cnt++;
            if(cnt % numRows == 0){
                i -= 2;
                j += 1;
                while(k < s.size() && i > 0){
                    arr[i--][j++] = s[k++];
                }
            }
        }
        string ans;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < 1000; j++){
                if(arr[i][j]){
                    ans += arr[i][j];
                }
            }
        }
        return ans;
    }
};