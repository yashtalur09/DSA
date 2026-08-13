class Solution {
    int func(int ind,vector<int>& cost,vector<int>& dp){
        if(ind==0) return cost[0];
        if(ind==1) return cost[1];
        if(dp[ind]!=-1) return dp[ind];
        int left=cost[ind]+func(ind-1,cost,dp);
        int right=INT_MAX;
        if(ind>=2){
            right=cost[ind]+func(ind-2,cost,dp);
        }
        return dp[ind]=min(right,left);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(func(n-1,cost,dp),func(n-2,cost,dp));
    }
};