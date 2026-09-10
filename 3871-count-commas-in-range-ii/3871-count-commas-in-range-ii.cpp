class Solution {
public:
    long long countCommas(long long n) {
        long long cnt=0;
        long long commas=1;
        long long lower=1000;
        while(lower<=n){
            long long upper=(lower*1000)-1;
            if(upper>n) upper=n;
            long long cntnos=upper-lower+1;
            cnt+=(cntnos*commas);
            commas++;
            lower=lower*1000;
        }
        return cnt;
    }
};