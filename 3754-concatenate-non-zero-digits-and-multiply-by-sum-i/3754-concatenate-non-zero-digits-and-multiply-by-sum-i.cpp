class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        int sum=0;
        string temp=to_string(n);
        string ans="";
        for(auto &c:temp){
            if(c!='0'){
                ans+=c;
            }
        }
        long long x=stoll(ans);
        for(auto &t:ans){
            int z=t-'0';
            sum+=z;
        }
        return x*sum;
    }
};