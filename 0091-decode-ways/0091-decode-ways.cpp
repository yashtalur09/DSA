class Solution {
    int func(int ind,string s,vector<int>& dp){
        if(ind<0) return 1;
        if(s[ind]=='0'){
            if(ind>=1){
                int num=(s[ind-1]-'0')*10+(s[ind]-'0');
                if(num==10 || num==20){
                    return func(ind-2,s,dp);
                }
            }
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int one=func(ind-1,s,dp);
        int two=0;
        if(ind>=1){
            int num=(s[ind-1]-'0')*10+(s[ind]-'0');
            if(num>=10 && num<=26){
                two=func(ind-2,s,dp);
            }
        }
        return dp[ind]=one+two;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return func(n-1,s,dp);
    }
};