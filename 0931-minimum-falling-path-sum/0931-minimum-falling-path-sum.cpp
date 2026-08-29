class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u=INT_MAX;
                if(i-1>=0) u=matrix[i][j]+dp[i-1][j];
                int ld=INT_MAX;
                if(j-1>=0 && i-1>=0) ld=matrix[i][j]+dp[i-1][j-1];
                int rd=INT_MAX;
                if(j+1<m && i-1>=0) rd=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(min(u,ld),rd);
            }
        }

        int mini=dp[n-1][0];

        for(int j=1;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }

        return mini;
    }
};