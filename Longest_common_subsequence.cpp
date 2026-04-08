class Solution {
public:
int solver (int i ,int j ,string &text1 , string &text2,vector<vector<int>> &dp){
    if (i == text1.size() || j == text2.size()){
        return 0;
    }
    if (dp[i][j]!=-1){
        return dp[i][j];
    }
    if (text1[i]==text2[j]){
        return dp[i][j] = 1 + solver(i+1,j+1,text1,text2,dp);
    }
    int a = solver(i+1,j,text1,text2,dp);
    int b = solver(i,j+1,text1,text2,dp);
    return dp[i][j] = max(a,b);
}
    int longestCommonSubsequence(string text1, string text2) {
        int i= 0, j = 0;
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = solver(i,j,text1,text2,dp);            
        return ans;
    }
};