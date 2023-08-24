class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int LCS[n + 5][m + 5];
        memset(LCS, 0, sizeof(LCS));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]){
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                }
                else{
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
                }
            }
        }
        return LCS[n][m];
    }
};