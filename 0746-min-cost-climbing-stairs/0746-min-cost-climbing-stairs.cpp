class Solution {
    // int func(int ind,vector<int>& cost,vector<int>& dp){
    //     if(ind==0) return cost[0];
    //     if(ind==1) return cost[1];
    //     if(dp[ind]!=-1) return dp[ind];
        
    // }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int ind=2;ind<n;ind++){
            int left=cost[ind]+dp[ind-1];
            int right=INT_MAX;
            if(ind>=2){
                right=cost[ind]+dp[ind-2];
            }
            dp[ind]=min(right,left);
        }
        return min(dp[n-1],dp[n-2]);
    }
};