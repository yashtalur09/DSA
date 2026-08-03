class Solution {
    int solve(vector<int>& stones,int i,vector<int>& dp){
        int n=stones.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int result=INT_MIN;
        result=max(result,stones[i]-solve(stones,i+1,dp));
        if(i+1<n){
            result=max(result,stones[i]+stones[i+1]-solve(stones,i+2,dp));
        }
        if(i+2<n){
            result=max(result,stones[i]+stones[i+1]+stones[i+2]-solve(stones,i+3,dp));
        }
        return dp[i]=result;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,-1);
        int diff=solve(stoneValue,0,dp);
        if(diff>0){
            return "Alice";
        }
        else if(diff<0){
            return "Bob";

        }
        else{
            return "Tie";
        }
    }
};