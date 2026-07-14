class Solution {
    int mod=1e9+7;
    int solve(vector<int>& nums,int i,int first,int second,vector<vector<vector<int>>> &dp){
        int n=nums.size();
        if(i==n){
            bool nonEmpty=(first!=0 && second!=0);
            bool equal=(first==second);
            if(nonEmpty && equal) return 1;
            else return 0;
        }
        if(dp[i][first][second]!=-1) return dp[i][first][second];

        int skip=solve(nums,i+1,first,second,dp);
        int take1=solve(nums,i+1,__gcd(first,nums[i]),second,dp);
        int take2=solve(nums,i+1,first,__gcd(second,nums[i]),dp);

        return dp[i][first][second]=(0LL+skip+take1+take2)%mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(nums,0,0,0,dp);
    }
};