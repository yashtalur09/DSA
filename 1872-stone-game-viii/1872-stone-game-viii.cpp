class Solution {
public:


    // int solve(int i,vector<int>& prefixSum,vector<int>& dp){
    //     int n=prefixSum.size();
    //     if(i==n-1){
    //         return prefixSum[n-1];
    //     }
    //     if(dp[i]!=-1) return dp[i];
        

    //     return dp[i]=max(take,nottake);
    // }

    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefixSum(n,0);
        vector<int> dp(n+1,0);
        prefixSum[0]=stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+stones[i];
        }
        dp[n-1]=prefixSum[n-1];
        for(int i=n-2;i>=1;i--){
            int take=prefixSum[i]-dp[i+1];
            int nottake=dp[i+1];
            dp[i]=max(take,nottake);
        }
        return dp[1];
    }
};