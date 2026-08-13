class Solution {
    int func(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int up=matrix[i][j]+func(i-1,j,matrix,dp);
        int left=INT_MAX;
        if(j>0){
            left=matrix[i][j]+func(i-1,j-1,matrix,dp);
        }
        int right=INT_MAX;
        if(j+1<m){
            right=matrix[i][j]+func(i-1,j+1,matrix,dp);
        }
        return dp[i][j]=min(up,min(left,right));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        int mini=INT_MAX;
        for(int j=0;j<m;j++){
            mini=min(mini,func(n-1,j,matrix,dp));
        }
        return mini;
    }
};